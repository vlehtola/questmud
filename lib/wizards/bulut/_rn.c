/* Based on Cendors copy command for QuestMUD */
/* Evil hax0r bulut */


#define PATH this_player()->query_path()
#define WIZARD_DIR "/wizards/"

status copy_file(string in, string out) {

  int f_size, current_byte,path;

  int max_byte;

  string txt,tmp;

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
    write("No such file '" + tmp + "'\n");
    return 1;
  }

  if(file_size(out) > 0) {

  write("File Already Exists: "+out+"\n");

  return 0;

  }
 if(valid_read(out,this_player()) == 0) {
  write("Access denied.\n");
  return 1;
}



write("Renaming "+in+" to "+out+"\n");

f_size = file_size(in);

  while(current_byte < f_size) {

  if(current_byte + 8192 > f_size)

    max_byte = f_size - current_byte;

  else

    max_byte = 8192;

    txt = read_bytes(in, current_byte, max_byte);

    write_file(out, txt);

    current_byte += max_byte;

    current_byte += sizeof(explode(txt, "\n")) - 1; 

}

return 1;

}





cmd_rn(string str) {

  string tmp, tmp2;

  if(!str) {

    write("## Usage   : rn [FROM_PATH] [TO_PATH]\n");

    write("   Example : rn /wizards/cendor/sword.c /wizards/cendor/eq/sword.c\n");
    write("   Example2: rn sword.c eq/sword.c\n");

    return 1;

  }

  if(sscanf(str, "%s %s" , tmp, tmp2) != 2)  return 0;


  if(!file_size(tmp2)) {

    write("No such file '" + tmp + "'\n");

    return 1;

  }



  copy_file(tmp,tmp2) ;
  rm(tmp);
  

  return 1;

}







