cmd_prompt(string str) {
  if(!str) {
   write("## Usage : Prompt [Your_prompt|clear]\n");
write("Try 'help prompt'\n");
  return 1;
}

if(str == "clear") {
  write("Prompt cleared.\n");
  this_player() -> set_prom(0);
  return 1;
}
write("Your prompt is now " + str + "\n");
this_player() -> set_prom(str);
return 1;
}
