signtool sign /v /tr http://timestamp.digicert.com /f VafraCA.pfx /fd SHA256 /td SHA256 vafra_v14.12.0_x86-64_vnni512_windows.exe
signtool sign /v /tr http://timestamp.digicert.com /f VafraCA.pfx /fd SHA256 /td SHA256 vafra_v14.12.0_x86-64_avx512_windows.exe
signtool sign /v /tr http://timestamp.digicert.com /f VafraCA.pfx /fd SHA256 /td SHA256 vafra_v14.12.0_x86-64_avx2_windows.exe
signtool sign /v /tr http://timestamp.digicert.com /f VafraCA.pfx /fd SHA256 /td SHA256 vafra_v14.12.0_x86-64_sse41popcnt_windows.exe

