#include <ansi.h>

inherit "obj/monster";
object armour;

reset(arg) {
    ::reset(arg);
    set_level(50);
    set_special(25);
    set_max_hp(query_max_hp()*5);
    set_str(query_str()*2); 
    set_name("beast");
    set_skill("tumble", 50); 
    set_short("an ENORMOUS three-headed Beast");
    set_long("This beast has been trapped here for a long time. It's so huge that your hands tremble.\n");
    set_al(0);
    set_aggressive(1);
    set_log();
    armour = clone_object("wizards/rehti/dormund/obj/tail.c");
    move_object(armour, this_object());
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Beast bites you with all it's three heads!\n");
  tell_object(ob, "First "+RED_F+"FLAMING"+OFF+" head!\n");
  ob->hit_with_spell(random(500), "fire");
  tell_object(ob, "Then "+BLUE_F+"ICY"+OFF+" head!\n");
  ob->hit_with_spell(random(500), "ice");
  tell_object(ob, "Then "+YELLOW_F+"SHOCKING"+OFF+" head!\n");
  ob->hit_with_spell(random(500), "electric");
  tell_object(ob, "Finally Beast "+RED_F+"LEAPS"+OFF+" for a Kill!\n");
  ob->hit_with_spell(random(1000)+500, "acid");
}
