cmd_grep(string str) {
  int count;
  int hits;
  int pos;
  string sstring;
  string line;
  string filename;
  string fn;
  
  count = 0;
  hits = 0;

  if (!str) { write("\nSyntax: grep <search string> <filename>\n\n"); return 0; }
  if (sscanf(str, "\"%s\" %s", sstring, filename) != 2) write("\nSyntax: grep <search string> <filename>\n\n"); return 0;
  write(sstring + filename);
  
  fn = "/" + this_player()->query_current_path()+ "/"+ filename;    
  if( file_size( fn ) != -1 ) { filename = fn; }
  
  while(read_file(filename, count, 1)) {
    line = read_file(filename, count, 1);
    if (strstr(line, sstring) != -1) {
      pos = strstr(line, sstring);
      write(filename + ": " + count + "," + pos + " : " + line);
      hits++;
    }
    count++;
  }
  write("\nFound " + hits + " of " + sstring + " in file " + filename + "\n\n");
  return 1;
}
