/* advanced typo fixing system //Celtron */

fix_file(string wrong, string right, string file) {
  string stream, start, end;
  stream = read_file(file);
  if(sscanf(stream, "%s"+wrong+"%s", start, end) == 2) {
    stream = start + right + end;
    write_file

}
