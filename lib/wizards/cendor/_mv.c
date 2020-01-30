/* Move command for QuestMUD by Cendor in 29th Aug 1997 */



#define WIZARD_DIR "/wizads/"

status copy_file(string in, string out) {

  int f_size, current_byte;

  int max_byte;

  string txt;

            

  if(file_size(out) > 0) {

  write("File Already Exists: "+out+"\n");

  return 0;

}



write("Moving "+in+" to "+out+"\n");

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

rm(in);

return 1;

}





cmd_mv(string str) {

  string tmp, tmp2;

  if(!str) {

    write("## Usage   : mv [FROM_PATH] [TO_PATH]\n");

    write("   Example : mv /wizards/cendor/sword.c /wizards/cendor/eq/sword.c\n");

    write("   Note    : I made this command so we can move files in mud. This\n");

    write("             command is not even NEARLY ready. This is just a fast\n");

    write("             hack of mv command. You must use FULL paths like in\n");

    write("             example above. Report all bugs to Cendor. Use this\n");

    write("             command with your own purpose. I am not responsible\n");

    write("             if this command bugs and you lose your original file.\n");

    return 1;

  }

  if(sscanf(str, "%s %s" , tmp, tmp2) != 2)  return 0;

  

  if(!file_size(tmp)) {

    write("No such file '" + tmp + "'\n");

    return 1;

    }

  if(!file_size(tmp2)) {

    write("No such dir '" + tmp + "'\n");

    return 1;

  }

  copy_file(tmp,tmp2) ;

  return 1;

}







