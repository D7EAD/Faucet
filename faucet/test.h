#include <random>
#include <ctime>
#include <msclr/marshal_cppstd.h>

using namespace System::Windows::Forms;
using namespace System::Net::NetworkInformation;
using namespace System::Net;
using namespace System::IO;
using namespace Newtonsoft::Json::Linq;

// function for performing dns tests
void leakTest(RichTextBox^ %output) {
	System::String^ id = System::Convert::ToString((rand() % 9999999 + 1000000));
	msclr::interop::marshal_context context;
	srand(time(NULL));
	for (int i = 1; i <= 15; i++) {
		System::String^ command = System::Convert::ToString(("ping -n 1 " + i + "." + id + ".bash.ws"));
		system(context.marshal_as<const char*>(command));
	}
	try {
		HttpWebRequest^ request = dynamic_cast<HttpWebRequest^>(WebRequest::Create("https://bash.ws/dnsleak/test/" + id + "?json"));
		request->Method = "GET";
		request->ContentType = "application/json";

		HttpWebResponse^ response = dynamic_cast<HttpWebResponse^>(request->GetResponse());
		Stream^ stream = response->GetResponseStream();
		StreamReader^ reader = gcnew StreamReader(stream);
		System::String^ result = reader->ReadToEnd();
		JToken^ obj = JToken::Parse(result);
		for each (auto value in obj) {
			if (value["type"]->ToString() == "ip") {
				output->Text += "Detected IP: " + value["ip"] + "  -  " + value["asn"];
			}
		}
		output->Text += "\n\nDetected DNS Servers:\n";
		for each (auto value in obj) {
			if (value["type"]->ToString() == "dns") {
				output->Text += "\t\tIP: " + value["ip"] + "\n\t\t\tASN: " + value["asn"] + "\n\t\t\tCountry: " + value["country_name"] + "\n";
			}
		}
	}
	catch (...) {
		output->Text = "Resolution failed!";
	}
}