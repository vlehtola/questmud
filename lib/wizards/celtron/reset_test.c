void reset(status arg) {
  write("Reset("+arg+")\n");
  if(arg) return;
  write("NO ARG\n");
}
