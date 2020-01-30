inherit "obj/monster";
object armour;
object weapon;

int q;
string str;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    q = 0;
    set_name ("knight");
    set_level (85);
    set_max_hp(query_max_hp()*5);
    set_str(query_str()*2);
    set_gender(1);
    set_al(20);
    set_al_aggr(200);
    set_skill("inner strength", 100);
    set_skill("strike", 100);
    set_skill("tremendous blow", 100);
    set_skill("punch", 100);
    set_skill("bare hands", 100);
    set_skill("attack", 100);
    set_skill("doublehit", 100);
    set_skill("critical", 100);
    set_skill("find weakness", 100);
    set_skill("enhance criticals", 100);
    set_skill("axes", 100);
    set_skill("cut", 100);
    set_skill("agility", 100); 
    set_skill("double strike", 100);
    set_skill_chance("strike", 100);
    set_alias("knight");
    set_race("human");
    set_short("Head Knight bearing the mark of Dormund is preparing castle defenses here.");
    set_long("This Knight seems to trained a lot!. He has enormous muscles and he seems to know how to use his sword. You should be very careful with him.\n");
    set_aggressive(0);
    armour = clone_object("wizards/rehti/dormund/obj/dormundplate.c");
    move_object(armour, this_object());
    init_command("wear plate mail");
    weapon = clone_object("wizards/rehti/dormund/obj/ekuaxe.c");
    move_object(weapon, this_object());
    init_command("wield axe");
    set_log();
}

catch_tell(str) {
string giver,item,tmp;
object ob, item_ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }
      item_ob = present("tail", this_object());
      if (!item_ob) { return; }
      if(item_ob->query_no_save()) return;
      if (item_ob->short() != "Tail of three-headed beast") {
 tell_object(ob, "The Knight says 'This is not what I'm looking for'.\n");
 tell_object(ob, "The knight hands the "+capitalize(item)+" back to you.\n");
         move_object(present(item,this_object()), ob);
         return;
      }
      if (ob && item_ob && item_ob->short() == "Tail of three-headed beast" &&
                !ob->query_quests("Kill the three-headed Beast")) {
tell_object(ob, "You complete the 'Kill the three-headed Beast' quest.\n");
call_other(ob, "set_quest", "Kill the three-headed Beast");
      }
      destruct(item_ob);
    }
}



ask_question(str) {
    if(str == "quest") {
         say("Knight says: 'Three-headed Beast should be killed.'\n");
         return 1;
    }
    if(str == "tail") {
         say("Knight says: 'If you have tail of that three-headed beast, you should give it to me.\n");
         return 1;
    }
    write("King says: 'I don't know anything about that'.\n");
    return 1;
}
