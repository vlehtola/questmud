inherit "obj/monster";
int number_of_guards;
object armour,weapon;
     
reset(arg) {
 
    string chat_str, a_chat_str;
    ::reset(arg);
    number_of_guards = 0;
    if(arg) { return; }
    set_level(15);
    set_name("draconian");
    set_alias("guard");
    set_short("Draconian guard");
    set_long("The draconian guard has a wicked look on his face when you approach.\n"+
             "He seems all but afraid of your presence.\n");
    set_al(-5);
    set_extra(1);
    set_aggressive(0);
    set_log();
    set_block_dir("east");
    set_spell_chance(100, "exs fla blt");
    set_skill("cast essence", 65);
    set_skill("cast fire", 60);
    set_skill("cast bolt", 70);
    set_skill("critical", 11);
    set_skill("stun", 15);
    set_skill("find weakness", 10);
    set_skill("slash", 25);  
    set_skill("blades", 60);
 

    if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
  "You better leave this place at once, before I call in guards to take care of you.\n";
        chat_str[1] =
          "Draconian hisses strange mantras.\n";
        chat_str[2] =
          "Draconian hisses madly at you.\n";
        chat_str[3]=
          "Draconian shows his terrible claws at you and makes a quick gesture across his throat.\n";
        chat_str[4]=
          "Draconian hisses, you have nothing to do further on, leave at once!\n";
 } 
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Draconian hurles: Help me guards!\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/walla/dl/eq/draccloak2");
    move_object(armour, this_object());                   
    init_command("wear cloak");
 
    weapon = clone_object("/wizards/walla/dl/weapons/clawedblade");
    move_object(weapon, this_object());
    init_command("wield blade");
 
    armour = clone_object("/wizards/walla/dl/eq/hoodofdrac");
    move_object(armour, this_object());
    init_command("wear hood");
 
    
}
 
 extra() {
    object drac_guard;
    if (!attacker_ob) {
        return;                      
    }
    if(random(number_of_guards + 1) == number_of_guards) {
        drac_guard = clone_object("/wizards/walla/dl/monsters/vakiogd");
        move_object(drac_guard, environment(this_object()));
        say("Draconian's screams are heard and another draconian flies in.\n");
        number_of_guards += 1;
     }
}
 
reduce_number() {
    number_of_guards -= 1;
}


