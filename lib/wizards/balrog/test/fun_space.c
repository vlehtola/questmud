mixed white_spaces(int curr, int max) {
  string retbuf;
  if (!curr) { write("No Current Value given to Function: White_Spaces"); return 0; }
  if (!max) { write("No Max Value given to Function: White_Spaces"); return 0; }
  if (curr == max || curr > max) { write("Current Equals/More than Max Value"); return 0; }
  if (curr < max) {
    for(curr;curr < max;curr++) {
      if(!retbuf) { retbuf = " "; } else { retbuf += " "; }
    }
  }
  return retbuf;
}
