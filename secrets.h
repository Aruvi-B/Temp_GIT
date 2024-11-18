#include <pgmspace.h>
#define SECRET
#define THINGNAME "Esp32"
const char WIFI_SSID[] = "CREAMCOLLAR_5G";
const char WIFI_PASSWORD[] = "creamcollar@2022"; 
const char AWS_IOT_ENDPOINT[] = "a2syxbmhe2unlb-ats.iot.ap-south-1.amazonaws.com";
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUCyOLDdlfNtI9QSrwzmbwD3IFYMkwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI0MTAwOTA4NDcw
NloXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAL8LxCRVN1EbMu2sqWiY
JxK423E728rm7XzZ139tzUG2lV2otoMg1nmC8gbtsYxTE7F299v7Yt0S6D3gwYPl
sX/PJmxdBe3DPoLF7/54plDn9E5gRJ8zMqKK5+fXprey//7tFcsByWGesoRl0Cbn
2rZM0cAcr0hX9jZC76s8U55P1LzLnlG2gd4Z7DVQczhLuWueCNQg9UmUdQ+QmW7M
75+jh+pzNdMUan/PX9EBTP1R+D6ZQ6il4tKaqXFqduBr0VwSEl0m4n/KGZgTMarx
udgObklJA2I0Of8dwQIT1NchGlOjW9wU1nTfN4eAik3uVx6LqCLex9rqSXcTYoM2
4AECAwEAAaNgMF4wHwYDVR0jBBgwFoAUv9jzFNnVKoiM6aBaK0ngfJ6u7CEwHQYD
VR0OBBYEFIk3e2DB1RS7WSaEHVdwUHJ4MFrGMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQAzjEaqVimskTG/CMtA5l3rwK0e
kovy5QvabrKZR7mk2giADBOq1RiUbQzPcnTPP+ea3ai4gVnrw1JTazJKbOmJduu6
mYZepvSIRdHBPNovs9hxYG6Mq0P/76lNl1byuo6BjGbhTcRCxc6WmikosdrDMJfW
fUbzjU7MLZsVziwc6FZgBDA/TYwWNqzJrkjrDzuymb8MM9yVongRWv73rhMtXBdG
GZ+wN/UK+S2bvZgIzemZIURnl5e5Q3ZdgqQ+uzbvAWUuMQFRyg8/M/f45Yt6w8+q
2GlkqZYouo3S85NzhhehphWS8AWNuw3v+P9elGq7eOoSb59P3uHEA5+SWC8i
-----END CERTIFICATE-----
)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEAvwvEJFU3URsy7aypaJgnErjbcTvbyubtfNnXf23NQbaVXai2
gyDWeYLyBu2xjFMTsXb32/ti3RLoPeDBg+Wxf88mbF0F7cM+gsXv/nimUOf0TmBE
nzMyoorn59emt7L//u0VywHJYZ6yhGXQJufatkzRwByvSFf2NkLvqzxTnk/UvMue
UbaB3hnsNVBzOEu5a54I1CD1SZR1D5CZbszvn6OH6nM10xRqf89f0QFM/VH4PplD
qKXi0pqpcWp24GvRXBISXSbif8oZmBMxqvG52A5uSUkDYjQ5/x3BAhPU1yEaU6Nb
3BTWdN83h4CKTe5XHouoIt7H2upJdxNigzbgAQIDAQABAoIBAQCxQfKIH4UGvOzA
923rvRir11bMNlTVavQ43kqDUlaavRTTZMGK4wH8llGHuiz9XOutwgtxUUrGgk93
cj066viI9KPa8WiZ1Yj/fzYQ7tKpyL21pr6k07UMeUN4qm9mjC/X0RRiWlMGP1+1
Vl4OaxtT/+yxiivcPLkWWX7Ua1HOVPsMzDrD/5GcKdX1PLIw9UX05UdsSyHVMD0B
B3fz2BkpSRjA/wEOLv1xaXyUt0omKUbYjI4VDimpEij4l4R08XRY23X9TYikUf44
Y7f74gXz0ojXjb++aUHHmYzWw+hWmxllbpazdA9eV/AP/aEFjhhkOUwtmr4zLuL1
DJ4VgaxBAoGBAOV0Ssne8AmZQuKnKuRjAb3rJiJrvalqJPUHDHO6Iktcs67Wygt9
Tsj+JXB/QyQaVonHuukUzd2HzxHnmNDyd1I0/fXN4/m8HUK0tilxaqSLgvM7LhHv
boTGNi9wnswvwfjrUPX1ZemyraugUns47gCk3pi0+elfEaz+x6eKYhsJAoGBANUl
8Rv8AjMF9PlzmG5r5837bhfvvhosAeqIl5OjE6k+mos+0JNKZF4sccbxtDHy77kt
LJ/PH9hdpx7EFGPGcsrhrljaRPwqMxqRMSubiqdtDYA1M4/uMrWTl3iCOe7MOoqA
I1zncS5dvIfoc+DRLmd/1iyBFW7Hb+PZ92PZT8M5AoGBAKWkeSUYUrKrOFTFFzq+
mpBPBD2PB+EYZkuY5g1ZTs6WwoQyPLNkp46DoeV/iamzdcuLK0x+H0uQchTb2z7j
+u2Woctj8fLkMT9pk6OBY9obeNI8Y7rA3UjuiklfBNQkmeQnhE+68vJtceBXIZQg
+ffvDV6yL0OgxPLdDqbNSJt5AoGACmhP3Y3wjY086PE8AChEqUodlg2euqhrb4g7
3nmX/CuSYDow9QAs5mxFIfGrWsUB74jFJQh4BZiNEHOCi1ylPkLGwI/nzmhBFosA
W6C8pHAuuJPgcKaw0yzhuICjU4WlVh3rnB2w6RKqofg3sEKGgYc8be/fnAkg7X83
FSkHPAECgYEAx2F36leeleQVa5RNy5gO2krv5e1teU3XMWUwwwU4K9IJzlPNUgEr
pZwTkva7aIsGfTxG5+y+PoTisGD+L3EmXNxfhi/dKFzuVxRcddDTmMyRzjYmKlZ+
SqVkIN1ePYYImRwgL8H38VrjyWt/00cM9YpuAymKK4/XIZfAiY8QZwU=
-----END RSA PRIVATE KEY-----
)KEY";
