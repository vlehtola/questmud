
cmd_defence(string arg) {
  call_other("/cmds/std/_combat.c", "cmd_combat", arg);
  return 1;
}

