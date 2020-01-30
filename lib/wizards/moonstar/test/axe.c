#include <ansi.h>
#define SAVE_DIR "/wizards/moonstar/"

inherit "obj/weapon";
int i;
string owner_name;
start() {
        set_class(100);
        set_sub_type("great axe");
        set_name("kragitu");
        set_alias("axe");
        set_short("A spiritual great axe 'Kra'Gi'Tu' "+get_short(i)+"");
        set_long("A green coloured great axe is emiting some strange glow.\n"+
                 "Rumors tells that this axe was created by ancient god\n"+
                 "called 'Ra'Mos'Tot' who took the challenge and fighted against\n"+
                 "the evil god 'Gar'. After the battle Ra'Mos'Tot looked the world\n"+
                 "and he decided to hide this axe of terror hoping that it wouldn't\n"+
                 "be founded anymore. There are some ancient runes on the axe.\n");
 	// Aina kun tama esine clonetaan, haetaan vanha data tiedostosta:
        //restore_object(SAVE_DIR+wielded_by->query_name());

set_stats("str", 10);
}
init() {
::init();
add_action("read", "read");
add_action("drain", "drain");
}

read(string str) {
  if(str != "runes") return 0;
  write("The runes say something about draining the dead souls with axe.\n");
  return 1;
}
drain(string str) {
        object ob;
        if(str != "corpse") return 0;
        if(!wielded_by) return 0;
        ob = present("corpse", environment(this_player()));
        if(!ob) {
                write("Axe burns your hand!\n");
                wielded_by->hit_with_spell(random(150), "physical");
                return 1;
        }
        if(!ob->query_corpse()) {
                write("You hear some unknown language inside your head.\n");
                return 1;
        }
        i += 1;
        write("You place the axe above the corpse and it drains the soul out from the corpse.\n");
        say(wielded_by->query_name()+" places something above the corpse and something rices out from the corpse.\n");
        destruct(ob);
        // Aina kun mosa drainitaan, tallennetaan uudet arvot datafiluun
        // save_object(SAVE_DIR+wielded_by->query_name());
return 1;
}


wield(string str) {
  ::wield(str);
  if(!wielded_by) return 0;
  write("The axe vibrates as you wield it.\n");
  return 1;
}

get_short(int i) {
        switch(i) {
                case 0..50: return ""+BLUE_F+"<glowing>"+OFF+"";
                case 51..150: return ""+BLUE_F+"<GLOWING>"+OFF+"";
                case 151..300: return ""+BLUE_F+"<radiating>"+OFF+"";
                case 301..700: return ""+BLUE_F+"<RADIATING>"+OFF+"";
                case 701..1500: return ""+BLUE_F+"<shimmering>"+OFF+"";
                case 1501..2900: return ""+BLUE_F+"<SHIMMERING>"+OFF+"";
                case 2901..5000: return ""+RED_F+"<burning>"+OFF+"";
                case 5001..8000: return ""+RED_F+"<BURNING>"+OFF+"";
                }
                return ""+RED_F+"<EVER FLAME>"+OFF+"";
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(6) != 0) return;
  tell_room(environment(wielded_by), "Kra'Gi'Tu flashes"+" as it SINKS inside the "+wielded_by->query_attack()->query_name()+" with "+RED_F+"FORCE"+OFF+".\n");
  wielded_by->query_attack()->hit_with_spell(random(500)+(i/4), "fire");
  return 1;
}

