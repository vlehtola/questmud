inherit "obj/monster";
int number_of_fighters;
object armour,sword;

reset(arg) {
    ::reset(arg);
    number_of_fighters = 0;
    if(arg) { return; }
    set_level(57);
    set_name("commander");
    set_short("The Commander of the Black Circle ");
    set_long("The commander of the legendary mercenary group is a truly imposing individual. His black plate armor is matched by his dark hair and ice-blue eyes. It is easy to see how he has risen to this position, as an aura of power surrounds him like a dark halo.\n");
    set_al(-160);
    set_extra(1);
    set_log();    
    set_gender(1);
    set_race("human");
    set_aggressive(1);
    
    armour = clone_object("/wizards/tiergon/eq/bclplate");
    move_object(armour, this_object());
    init_command("wear armour");
  
    sword = clone_object("/wizards/tiergon/eq/bclsword");
    move_object(sword, this_object());
    init_command("wield sword");
}
extra() {
    object fighter;
    int i;
    if (!attacker_ob) { 
        return; 
    }
    if(!query_spell() && !this_object()->query_stunned()) {
    if(random(number_of_fighters + 1) >= number_of_fighters) {
        i = random(5);
        if (i <= 1) { 
        fighter = clone_object("/wizards/tiergon/dungeon/bcamazonian3");    
        }
        if (i == 2) {
        fighter = clone_object("/wizards/tiergon/dungeon/bcfighter3");    
        }
        if (i == 3) {
        fighter = clone_object("/wizards/tiergon/dungeon/bcpriest3");    
        }
        if (i == 4) {
        fighter = clone_object("/wizards/tiergon/dungeon/bcmage");    
        }   
        move_object(fighter, environment(this_object()));
        say("The Commander summons reinforcements!");

     number_of_fighters  += 1;
    }
}
}

reduce_number() {
    number_of_fighters -= 1;
}
