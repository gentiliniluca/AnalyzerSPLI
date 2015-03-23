#include "my.h"
#include<string.h>

void liv7(u_int len,const u_char *p, u_int ssap, u_int dsap) {
	int i;
	int flag_ftp_req = 0;
	int flag_ftp_res = 0;
	int flag_ftp_dat = 0;
	int flag_ftp_raw = 0;

  	if((int)len<=0) {
  		return;
  	}
  	
  	colore(6);
  	
  	if (ssap==21 || ssap==20 || dsap==21 || dsap==20) {
		if(!r_ftp) {
			return;
		}
		
	    	if(p_ftp) {	
	    		if (ssap == 21) {
	    			myprintf("FTP | Response\n    | ");
	    			flag_ftp_res = 1;
	    		}
	    		if(dsap == 21){
	    			myprintf("FTP | Request\n    | ");
	    			flag_ftp_req = 1;
	    		}
	    		if (ssap == 20) {
	    			myprintf("FTP | Data\n\n");
	    			flag_ftp_dat = 1;
	    		}
	    		if(dsap == 20){
	    			myprintf("FTP | Data\n\n");
	    			flag_ftp_dat = 1;
	    		}
    		
		  	for(i=1; i<=len; i++) {
				if(isprint(*p)) {
					myprintf("%c",*p);
				} else {
					if(((*p) == '\n') || ((*p) == '\r') || ((*p) == '\t')) {
						myprintf("%c",*p);
					} else	{
						myprintf(".");
						flag_ftp_raw = 1;
					}
				}
			
				if(isascii(*p)){
					fprintf(mem,"%c",*p);
				} else {
					fprintf(mem,".");
				}
				/*if((i%70)==0){
					myprintf("\n     |");
				}*/
				
				p++;
		  	}
		  	if(flag_ftp_raw) {
		  		myprintf("\n");
		  	}
		  	myprintf("\n");
		  	fflush(mem);
		  	decoded = 1;
	  	}
  	}
}
