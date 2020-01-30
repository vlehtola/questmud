/* Copy command for QuestMUD by Cendor in 29th Aug 1997 */
/* Fixed a problem that corrupted large files ++ Nalle, May 2002 */

#define PATH this_player()->query_path()
#define WIZARD_DIR "/wizards/"

status copy_file(string in, string out, int force) 
{
  int f_size, current_byte, path, max_byte;
  string txt,tmp;

  current_byte=0;

  tmp = extract(out,0,0);

  if(tmp != "/") {
    out = "/"+PATH+"/"+out;
  }

  tmp = "";
  tmp = extract(in,0,0);
  if(tmp != "/") {
    in = "/"+PATH+"/"+in;
  }
  if(file_size(in) < 1) {
    write("No such file. ('" + tmp + "')\n");
    return 1;
  }

	if(file_size(out) > 0)
	{
	 if(!force) 
		{
		 write("File Already Exists. ('"+out+"')\n");
	 	 return 0;
		} 
		else
		{
		 force=2;
		 if(!rm(out)) 
			{
			 write("Insufficient privileges to replace target file.\n");
			 return 0;
			}
		}
	}

	if(valid_read(out,this_player()) == 0) 
	{
	 write("Access denied.\n");
 	 return 1;
	}

	if(force != 2)
	  {
	   write("Copying '"+in+"' to '"+out+"'\n");
	  }
	else
	  {
	   write("Replaced '"+out+"' with '"+in+"'\n");  
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

/*****************************************/

cmd_cp(string str) 
{
  string tmp, tmp2, tmp3;
  int force;

  force=0;

  if(!str) 
  {
    write(" Usage   : cp [SWITCH] [FROM_PATH] [TO_PATH]\n");
    write("   Example : cp /wizards/cendor/sword.c /wizards/cendor/eq/sword.c\n");
    write("   Example2: cp sword.c eq/sword.c\n");
    return 1;
  }

  // Switch-support
  if(sscanf(str, "%s %s %s" , tmp, tmp2, tmp3) == 3)
	{
	 if(tmp == "-f" || tmp == "--force") 
		{ force=1; str=tmp2+" "+tmp3; }
	 if(tmp3 == "-f" || tmp3 == "--force") 
		{ force=1; str=tmp+" "+tmp2; }
	}

  if(sscanf(str, "%s %s" , tmp, tmp2) != 2)  return 0;

  if(!file_size(tmp2)) 
    {
     write("No such file '" + tmp + "'\n");
     return 1;
    }

  copy_file(tmp,tmp2, force);
  return 1;
}







