get_time() { return 3; }
query_type() { return "neutral"; }

resolve_skill() {
  int i;
  i = this_player()->query_skills("knowledge of the way");
  write("You know the following sidepaths of the Way:\n");
  if(i>=20) {
    write("Way of the kick and Way of the punch\n");
  }
  if(i>=30) {
    write("Way of the wood and Way of the stone\n");
  }
  if(i>=40) {
    write("Way of understanding\n");
  }
  if(i>=50) {
    write("Inner path\n");
    write("Way of shadows\n");
  }
  if(i>=60) {
    write("Secret path\n");
    write("Way of the sword\n");
    write("Way of arms\n");
  }
  write("Remember the right syntax: say I seek the <path>\n");
  write("Suin is very conservative in these matters.\n");
}

fail_skill() {
  resolve_skill();
}

