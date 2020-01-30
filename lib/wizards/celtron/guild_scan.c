/* scans guildnames and maxlevels for www purposes */

scan() {
  string *dirs, *files, file, *output;
  int d, f;

  output = ({"", });
  dirs = get_dir("/guilds/*");
  for(d = 0; d < sizeof(dirs); d++) {
    files = get_dir("/guilds/"+dirs[d]+"/*");
    output += ({ "\n"+dirs[d]+"\n", });
    for(f= 0; f < sizeof(files); f++) {
      if(dirs[d][0..0] != "." && files[f][0..0] != "." && files[f][strlen(files[f])-2 .. strlen(files[f])-1] == ".c") {
        file = "/guilds/"+dirs[d]+"/"+files[f];
//        write("Calling "+file+"\n");
        if(file->guild_name()) 
          output += ({ file->guild_name() + " ("+ file->guild_max_level() +")", });
      }
    }
  }
  files = output;
  for(d = 0; d < sizeof(files); d++) {
    write(capitalize(files[d])+"\n");
    write_file("/wizards/celtron/GUILD_SCAN_OUTPUT", capitalize(files[d])+"\n");
  }
}
