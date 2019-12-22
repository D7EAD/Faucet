#include "test.h"

namespace faucet {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class main_form : public System::Windows::Forms::Form {
		private: System::ComponentModel::Container^ components;
		private: System::Windows::Forms::RichTextBox^ outputField;

		public: main_form(void)	{
			InitializeComponent();
		}

		protected: ~main_form() {
			if (components) {
				delete components;
			}
		}

		void InitializeComponent(void) {
			this->outputField = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// outputField
			// 
			this->outputField->BackColor = System::Drawing::Color::Black;
			this->outputField->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->outputField->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputField->ForeColor = System::Drawing::Color::White;
			this->outputField->Location = System::Drawing::Point(2, 2);
			this->outputField->Name = L"outputField";
			this->outputField->ReadOnly = true;
			this->outputField->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->outputField->Size = System::Drawing::Size(687, 334);
			this->outputField->TabIndex = 1;
			this->outputField->Text = L"";
			// 
			// main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(695, 339);
			this->Controls->Add(this->outputField);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"main_form";
			this->Text = L"Faucet | Results";
			this->Load += gcnew System::EventHandler(this, &main_form::Main_form_Load);
			this->ResumeLayout(false);

		}
		private: System::Void Main_form_Load(System::Object^ sender, System::EventArgs^ e) {
			leakTest(outputField);
		}
	};
}
