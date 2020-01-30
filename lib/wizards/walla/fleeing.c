/* monsu pakenee 3k hp steppien jalkeen rajatulle 4 roomin alueelle. castaa juoksun jalkeen yhden healin. */
/* muuten blastaa boltilla. //Celtron */

#define WIMPY_HP_STEP 15000
inherit "obj/monster";
int temp_hp;

reset(arg) {
    string chat_str;
    object armour, armour2, armour3, armour4;
    int i;
    ::reset(arg);
    if (arg) { return; }
    i = random(3);

    set_level(65);
    set_alias("human");
    set_name("witch");
    set_short("The damned witch of dark forest ");
    set_long("She must be the ugliest woman in this realm. Her face, hands, legs and her\n"+
        "whole body is covered with black hair. Her finger nails are long and sharp,\n"+
        "deadly sharp. Her blood red eyes are full of fury.\n");
    set_al(-30);
    set_aggressive();
    set_gender(2);
    set_race("human");
    set_log(1);
    set_spell_chance(90, "exs brr blt");
    set_skill("cast essence", 90);
    set_skill("cast ice", 90);
    set_skill("cast bolt", 90);
    set_skill("mana control", 90);

    set_skill("channel", 90);
    set_skill("cast major", 90);
    set_skill("cast heal", 90);
    set_skill("cast divine", 90);
    set_skill("mastery of medicine", 60);

    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
          "Witch says: 'I'm free again. Now i can rule the world.'\n";
    }
    load_chat(1, chat_str);
    set_special(40);
    temp_hp = query_hp();

    armour = clone_object("/wizards/irmeli/bwp/eq/belt.c");
    move_object(armour, this_object());
    init_command("wear belt");

    if(i==0) { armour2 = clone_object("/wizards/irmeli/bwp/eq/robes.c");
    move_object(armour2, this_object());
    init_command("wear robes");

     }
    if(i==1) { armour3 = clone_object("/wizards/irmeli/bwp/eq/ring.c");
    move_object(armour3, this_object());
    init_command("wear ring");

     }
    if(i==2) { armour4 = clone_object("/wizards/irmeli/bwp/eq/collar.c");
    move_object(armour4, this_object());
    init_command("wear collar");
}
}
special_move() {
  object ob, spell;
  string r, tmp;
  if(temp_hp - WIMPY_HP_STEP < query_hp()) return 0;
  temp_hp = query_hp();
  r = ({"lost1","lost2","lost3","lost4",});

  tmp = r[random(sizeof(r))];
  ob = find_object("/wizards/irmeli/bwp/"+tmp);

  while(ob && environment(this_object()) == ob) {
    tmp = r[random(sizeof(r))];
    ob = find_object("/wizards/irmeli/bwp/"+tmp);
  }

  this_object()->move_interrupt_spell();
  tell_room(environment(this_object()), short()+"lets out a terrible scream and disappears behind the bushes!\n");
  move_object(this_object(), "/wizards/irmeli/bwp/"+tmp);
  tell_room(environment(this_object()), short()+"appears from the bushes!\n");

  spell = clone_object("obj/spell");
  spell->start_spell("chl hea mar at witch", this_object());
  }


