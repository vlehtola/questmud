/* Copy-machine for strongholds, ripped from QuestMUD's cp-cmd by Astarel */

status copy_file(string in, string out, int force) 
{
  int f_size, current_byte, path, max_byte;
  string txt,tmp;

  current_byte=0;

  tmp = extract(out,0,0);

  if(tmp != "/") {
    out = "/castle/"+out;
  }

  tmp = "";
  tmp = extract(in,0,0);
  if(tmp != "/") {
    in = "/castle/"+in;
  }
  if(file_size(in) < 1) {
    //write("No such file. ('" + tmp + "')\n");
    return 1;
  }

	if(file_size(out) > 0)
	{
	 if(!force) 
		{
		 //write("File Already Exists. ('"+out+"')\n");
	 	 return 0;
		} 
		else
		{
		 force=2;
		 if(!rm(out)) 
			{
			 //write("Insufficient privileges to replace target file.\n");
			 return 0;
			}
		}
	}

	if(valid_read(out,this_player()) == 0) 
	{
	 //write("Access denied.\n");
 	 return 1;
	}

	if(force != 2)
	  {
	   //write("Copying '"+in+"' to '"+out+"'\n");
	  }
	else
	  {
	   //write("Replaced '"+out+"' with '"+in+"'\n");  
	  }

	f_size = file_size(in);

	while(current_byte < f_size) 
	{
 	if(current_byte + 8192 > f_size)
    	  max_byte = f_size - current_byte;
  	else
    	  max_byte = 8192;
    	  txt = read_bytes(in, current_byte, max_byte);
    	  write_file(out, txt);
    	  current_byte += max_byte;
	}

 return 1;
}






