cmd_grep(string str) {
  int count;
  int hits;
  int pos;
  string *strs;
  string line;
  string filename;
  
  if (!str) { write("Syntax: grep <search string> <filename>\n\n"); return 0; }

  count = 0;
  hits = 0;
  strs = explode(str, " ");

  filename = "/" + this_player()->query_current_path()+ "/"+ strs[1];    
  if( file_size( filename ) != -1 ) { strs[1] = filename; }
  if (!strs[0]) { write("Search string missing: Syntax \"grep <search string> <filename>\""); return 0; }
  if (!strs[1]) { write("Filename missing: Syntax \"grep <search string> <filename>\""); return 0; }
  
  while(read_file(strs[1], count, 1)) {
    line = read_file(strs[1], count, 1);
    if (strstr(line, strs[0]) != -1) {
      pos = strstr(line, strs[0]);
      write(strs[1] + ": " + count + "," + pos + " : " + line);
      hits++;
    }
    count++;
  }
  write("\nFound " + hits + " of " + strs[0] + " in file " + strs[1] + "\n\n");
  return 1;
}
