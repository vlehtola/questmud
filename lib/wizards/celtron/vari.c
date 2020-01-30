#define COLOR sprintf("%c",27)+"[1;31m"
#define OFF sprintf("%c",27)+"[0m"

object ob;

reset(arg) {
  if(arg) return;
  ob = find_player("muadib");
  if(ob->query_wizuvarjo()) return;
  shadow(ob, 1);
  tell_object(ob, "wiz shadow start\n");
  call_out("blur", 5);
}

blur() {
  tell_object(ob, COLOR);
  call_out("blur", 5);
}

look(arg,arg2,arg3,arg4) {
  ob->look(arg,arg2,arg3,arg4);
  tell_object(ob, COLOR);
  return 1;
}
