#include <ansi.h>
#define BB BOLD+BLUE_B+BLACK_F
#define W WHITE_B+BLACK_F
#define O OFF

inherit "obj/weapon";

start() {
  set_class(6);
  set_sub_type("hand axe");
  set_name("svp");
  set_alias("bottle");
  set_short("            "+W+"ta"+BB+"in"+O+W+"nuttaa"+O+"\n"
       "            SVP <bright "+BB+"miehen  ku"+O+" glow>\n"+
       "                        "+W+"mi"+BB+"eh"+O+W+"en!!!!"+O);
  set_long("Suomiviinapullo.\n");
 
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  tell_room(environment(wielded_by), wielded_by->query_attack()->query_name()+"'s soul has been drained into the strange bottle.\n");
  wielded_by->query_attack()->death();
  return 1;
}