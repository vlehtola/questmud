#include <ansi.h>

inherit "obj/monster";
int i,ii;
int number_of_hellhound;
reset(arg) {

        ::reset(arg);
        number_of_hellhound = 0;
        if(arg) {return; }
        set_name("erclups");
        set_alias("demon");
        set_race("demon");
        set_mage(1);
        set_level(110+random(10));
        set_special(8);
        set_extra(1);
        set_exp(99122678);
        set_max_hp(query_hp() + 800000);
        set_int(query_int()*4);
        set_str(query_str()+500);
        set_dex(query_dex()*3);
        set_wis(query_wis()*3);
        set_con(query_con()*3);
        set_al(-100);
        set_gender(1);
        set_short("Erclups the demon lord");
        set_long("taa tulis niiQ ja tappais sen.\n");
      set_skill("deceived attack", 90);
      set_skill("bare hands", 100);
      set_skill("punch", 100);
      set_skill("throw weight", 100);
      set_skill("dodge", 100);
      set_skill("parry", 100);
      set_skill("weapon parry", 100);
      set_skill("tumble", 65);
      set_skill("reflect spell", 100);
      set_skill("counter spell", 100);
      set_skill("blades", 100);
      set_skill("slash", 100);
      set_mage();
      set_spell_chance(95, "exs zzt strm");
      set_spell_chance(95, "exs fla strm");
      set_spell_chance(95, "exs brr strm");
      set_skill("battlecast", 100);
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
      //set_log();//

/*
        move_object(sword, this_object());
        init_command("wield sword");
*/
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
  tell_room(environment(this_object()), "Erclups says 'Your blast is weak.'\n");

  //Kutsutaan 10 minuutin p��st� t�t� funktiota
  call_out("change_resists",450);
}
extra() {
    object hellhound;
    if (!attacker_ob) {
        return;
    }
    if(random(number_of_hellhound + 1) == number_of_hellhound) {
        hellhound = clone_object("/wizards/yodin/hellhound");
        move_object(hellhound, environment(this_object()));
        say("Earth crumbles and hellhound crawl up from ground.\n");
        number_of_hellhound += 1;
    }
}

reduce_number() {
    number_of_hellhound -= 1;
}


special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Erclups screams in rage and "+BOLD+RED_F+"SLAMS"+OFF+" your head to the floor.\n");
  say("Erclups screams in rage and slams his strength and SLAMS "+ob->query_name()+" \n"+
  "head on the floor.\n", ob);
  ob->hit_with_spell(3000, "physical");
}


