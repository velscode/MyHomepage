#include <stdio.h>
#include <string.h>

int main()
{
	char temp [1024];
	FILE *fp_r, *fp_w;
	
	fp_r = fopen("Pages.txt","r");
	
	if(fp_r == NULL)
	{
		printf("Cannot open Pages.txt!\n");
		return 1;
	}
	
	fp_w = fopen("MyHomepage.html","w");
	
	fprintf(fp_w,"\
<!DOCTYPE html>\n\
<html>\n\
    <head>\n\
    	<meta charset=\"GB2312\">\n\
        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n\
        <title>MyHomepage</title>\n\
        <meta http-equiv=\"Content-Language\" content=\"Microsoft YaHei\">\n\
        <meta http-equiv=\"imagetoolbar\" content=\"no\">\n\
        <meta name=\"MSSmartTagsPreventParsing\" content=\"true\">\n\
        <link rel=\"stylesheet\" href=\"./global.css\">\n\
        <link rel=\"stylesheet\" href=\"./font-awesome.min.css\">\n\
    </head>\n\n\
    <body>\n\
        <div class=\"global-body\">\n\
            <div class=\"card-dwg-hrefc\">\n");
	
	while( !feof(fp_r) )
	{
		fscanf(fp_r,"%s",temp);
		
		if(strcmp(temp,"TITLE") == 0)
		{
			fscanf(fp_r,"%s",temp);
			fprintf(fp_w,"\
                <div class=\"card-dwg-title\">\n\
                <span>%s</span>\n\
                </div>\n",temp);
		}
		else if ( strcmp(temp,"PAGES") == 0 )
		{
			fscanf(fp_r,"%s",temp);
			fprintf(fp_w,"\
                <a class=\"card-dwg-href\" href=\"%s\" target=\"_blank\">\n\
                <div class=\"card-dwg-href-div\">\n",temp);
                
                
			fscanf(fp_r,"%s",temp);
			fprintf(fp_w,"\
                    <div class=\"card-dwg-href-img\" style=\"background-image: url(&#39;%s&#39;);\"></div>\n"
					,temp);
					
			fscanf(fp_r,"%s",temp);	
			fprintf(fp_w,"\
                    <div class=\"card-dwg-href-name\">%s</div>\n"
					,temp);	
		
			fscanf(fp_r,"%s",temp);
			fprintf(fp_w,"\
                    <div class=\"card-dwg-href-abstract\" title=\"%s\">%s</div>\n"
					,temp,temp);	
					
			fprintf(fp_w,"\
                </div>\
                </a>");	
		}
		else
		{
			;
		}
	}
	fclose(fp_r);
	
	fprintf(fp_w,"\
            </div>\n\
        </div>\n\
    </body>\n\
</html>");
	
	fclose(fp_w);
		
	return 0;
}


