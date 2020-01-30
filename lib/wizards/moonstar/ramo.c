#include <ansi.h>

inherit "obj/monster";
int i,ii;
int y;
reset(arg) {
        object money;
        object staff,shield,fullplate,circlet,axe,amu;
        y = random(3);
        ::reset(arg);
        if(arg) {return; }
        set_name("Ra'Mos'Tot");
        set_alias("god");
        set_race("human");
        set_mage(1);
        set_level(110+random(2));
        set_exp(89174834);
        set_max_hp(query_hp() + 400000);
        set_int(query_int()*3);
        set_str(query_str()+400);
        set_dex(query_dex()*2);
        set_wis(query_wis()*2);
        set_con(query_con()*2);
        set_al(0);
        set_gender(1);
        set_short(""+RED_F+"The forgotten god of the world, Ra'Mos'Tot"+OFF+" ");
        set_long("The forgotted god Ra'Mos'Tot is one of the elder ones,\n"+
                 "who created the world among some other gods.\n"+
                 "After his battle against evil god Gar, no one\n"+
                 "has seen him. Now he has come back to save\n"+
                 "the world and destroy the evil ones.\n");
      set_skill("deceived attack", 93);
      set_skill("bare hands", 100);
      set_skill("punch", 100);
      set_skill("throw weight", 100);
      set_skill("dodge", 100);
      set_skill("parry", 100);
      set_skill("weapon parry", 100);
     set_skill("tumble", 65);
      set_skill("reflect spell", 100);
      set_skill("counter spell", 100);
      set_skill("moonstar spessu", 100);
      set_skill_chance("moonstar spessu", 100);
      set_mage();
      set_spell_chance(85, "exs zzt strm");
      set_spell_chance(85, "exs fla strm");
      set_spell_chance(85, "exs brr strm");
      set_skill("cast essence", 100);
      set_skill("cast electric", 100);
      set_skill("cast fire", 100);
      set_skill("cast ice", 100);
      set_skill("cast storm", 100);
      set_skill("theory of electricity", 100);
      set_skill("lore of cold", 100);
      set_skill("knowledge of heat", 100);
      set_skill("mana control", 100);
      set_skill("chanting", 100);
      set_skill("agility", 80);
      set_skill("abjuration", 100);
      set_spell_chance(75, "kyo brr tdr");
      set_skill("cast abjuration", 100);
      set_skill("cast ice", 100);
      set_skill("cast alteration", 100);
      set_log();
    set_move_at_random(3);
        circlet = clone_object("/wizards/moonstar/areas/mosnotar/forest/eq/circlet.c");
        move_object(circlet, this_object());
        init_command("wear circlet");
        amu = clone_object("/wizards/moonstar/areas/mosnotar/forest/eq/amulet.c");
        move_object(amu, this_object());
        init_command("wear amulet");

        fullplate = clone_object("/wizards/moonstar/areas/mosnotar/forest/eq/fullplate.c");
        move_object(fullplate, this_object());
        init_command("wear mail");

       if(y == 0) {
        staff = clone_object("/wizards/moonstar/areas/mosnotar/forest/eq/staff.c");
        move_object(staff, this_object());
        init_command("wield staff");
}
     if(y == 1)  {
        shield = clone_object("/wizards/moonstar/areas/mosnotar/forest/eq/shield.c");
        move_object(shield, this_object());
}
      if( y == 2)  {
        axe = clone_object("/wizards/moonstar/areas/mosnotar/forest/eq/axe.c");
        move_object(axe, this_object());
        init_command("wield axe");
}
        //10 min v�lein uudet resistit
        call_out("change_resists",450);
}

//T�m� funktio muuttaa resistit
change_resists() {
//Setataan resistit nolliin
set_resists("fire",0);
set_resists("cold",0);
set_resists("electric",0);
  //Arvotaan uudet resistit
  //strong-mosilla on +10 leveli� kun arvotaan resistej�
  random_resists(query_level()+10);

  //Hieno viesti pelaajille
  tell_room(environment(this_object()), "Kaix glows white as he changes his powers.\n");

  //Kutsutaan 10 minuutin p��st� t�t� funktiota
  call_out("change_resists",450);
}


