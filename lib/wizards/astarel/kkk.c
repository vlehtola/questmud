status copy_file(string in, string out) {
  int f_size, current_byte;
  int max_byte;
  string txt;
            
  if(file_size(out) > 0) {
  return 0;
}

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








