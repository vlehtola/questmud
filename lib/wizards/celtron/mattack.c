short() { return "kampe. (Type: mattack <monster> <target>)"; }
init() {
  add_action("m_attack", "mattack");
}
id(str) { return str == "kampe"; }

m_attack(string str) {
  string str2;
  object ob, ob2;
  if(!str || sscanf(str, "%s %s", str, str2) != 2) return 0;
  ob = present(str, environment(this_player()));
  if(!ob) return 0;
  ob2 = present(str2, environment(this_player()));
  ob->attack_object(ob2);
  write("Attacking.\n");
  return 1;
}
