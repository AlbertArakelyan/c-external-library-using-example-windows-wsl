#include <stdio.h>
#include <hpdf.h>

int main() {
	printf("We are generating your static PDF...\n");

	HPDF_Doc pdf = HPDF_New(NULL, NULL);
	HPDF_Page page = HPDF_AddPage(pdf);

	HPDF_Page_BeginText(page);
	HPDF_Page_SetFontAndSize(page, HPDF_GetFont(pdf, "Helvetica", NULL), 20);
	HPDF_Page_MoveTextPos(page, 50, 750);
	HPDF_Page_ShowText(page, "Hello from Linux (WSL from Windows) + libharu"); // which we just successfully installed
	HPDF_Page_EndText(page);

	HPDF_Page_BeginText(page);
	HPDF_Page_SetFontAndSize(page, HPDF_GetFont(pdf, "Helvetica", NULL), 20);
	HPDF_Page_MoveTextPos(page, 50, 850);
	HPDF_Page_ShowText(page, "Even though we installed wverything perfectly, we still had linking problems with running our pdf-gen.exe");
	HPDF_Page_EndText(page);

	HPDF_SaveToFile(pdf, "output.pdf");
	HPDF_Free(pdf);

	return 0;
}
