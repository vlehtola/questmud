/* fixed by Nalle 030602 */

start(string prefix) {
  write("Everything you type will now have prefix '"+prefix+"'.\n");
  write("End rep with '**'.\n");
  input_to("next",0, prefix);
}

next(string input, string prefix) {
  if (input == "**") 
 { write("Exited rep mode.\n"); destruct(this_object()); return 1; }
  command(prefix+" "+input);

  input_to("next",0, prefix);
}

