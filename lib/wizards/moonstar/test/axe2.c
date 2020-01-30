#include <ansi.h>
inherit "obj/weapon";

start() {
        set_class(100);
        set_sub_type("great axe");
        set_name("kragitu");
        set_alias("axe");
        set_short("A great axe of morning sky");
        set_long("A green coloured great axe is emiting some strange glow.\n"+
                 "Rumors tells that this axe was created by ancient god\n"+
                 "called 'Ra'Mos'Tot' who took the challenge and fighted against\n"+
                 "the evil god 'Gar'. After the battle Ra'Mos'Tot looked the world\n"+
                 "and he decided to hide this axe of terror whit his staff hoping\n"+
                 "that it wouldn't be founded anymore. It's rumoured that this\n"+
                 "axe holds many magical powers.\n");
        set_stats("str", 10);
        set_stats("con", 10);

}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(7) != 0) return;
  tell_room(environment(wielded_by), "The great axe of morning sky flashes as it SINKS inside the "+wielded_by->query_attack()->query_name()+" with "+RED_F+"FORCE"+OFF+".\n");
  wielded_by->query_attack()->hit_with_spell(random(150)+200,"physical");
  return 1;
}
