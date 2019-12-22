# Faucet
Have you ever been worried that your DNS servers might be screwing your privacy over whilst using a VPN? Well, now you can easily check your DNS configuration for leaks with only two clicks!

<br/>

# What It Does
When opened, Faucet will attempt to resolve a bogus hostname 15 times--this is done in your terminal window. Once finished, the domain name servers that are detected will be displayed in a result window in the following format:
  - Your IP: [IP] - [ASN / ISP]
  - Detected DNS Servers:
      - IP: [IP]
        - ASN: [ASN / ISP]
        - Country: [country]
      - ...and so on for every detected server.
