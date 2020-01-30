/*
 * This is a decaying corpse. It is created automatically
 * when a player or monster dies.
 */

#define DECAY_TIME      120
#define RACE_D "/daemons/race_stats"

inherit "/obj/food";

string name;
int decay, level, animal;


prevent_insert() {
    write("The corpse is too big.\n");
    return 1;
}

init() {
  if(RACE_D->query_race_stat(this_player()->query_race(), "can_eat_corpses") ) {
    ::init();
  }
  add_action("search", "search");
}

reset(arg) {
    if (arg)
        return;
    name = "noone";
    decay = 2;
 
    set_strength(
(previous_object()->query_animal()+1)*500*previous_object()->query_level()
                );
}

set_name(n) {
    name = n;
    level = previous_object()->query_level();
    animal = previous_object()->query_animal();
    call_out("decay", DECAY_TIME);
  if(!name) name = "no one";
}

short() {
    if (decay < 2)
        return "The somewhat decayed remains of " + capitalize(name);
    return "Corpse of " + capitalize(name);
}

long() {
    write("This is the dead body of " + capitalize(name) + ".\n");
    if (animal) { write("It is an animal corpse.\n"); }
}

id(str) {
    return str == "corpse" || str == "corpse of " + name ||
        str == "remains";
}

decay() {
    object undead,env;
    decay -= 1;
    if (decay > 0) {
        call_out("decay", 20);
        return;
    }
    env = environment(this_object());
    if(!random(20) && env && !living(env) && level > 9) {
      undead = clone_object("/world/monsters/undead");
      undead->set_lvl(level);
      undead->set_nam(name);
      move_object(undead,environment(this_object()));
    }
    destruct(this_object());
}

can_put_and_get() { return 1; }

search(str)
{
    object ob;
    if (!str || !id(str))
        return 0;
    ob = present(str, environment(this_player()));
    if (!ob)
        ob = present(str, this_player());
    if (!ob)
        return 0;
    write("You search " + str + ", and find:\n");
    say(call_other(this_player(), "query_name") + " searches " + str + ".\n");
    if (!search_obj(ob))
        write("\tNothing.\n");
    else
        write("\n");
    return 1;
}

search_obj(cont)
{
    object ob;
    int total;
     
    if (!call_other(cont, "can_put_and_get"))
        return 0;
    ob = first_inventory(cont);
    while(ob) {
        total += 1;
        write(call_other(ob, "short"));
        ob = next_inventory(ob);
        if(ob) write(", ");
    }
    return total;
}

autoextract_obj(object cont)
{
    object ob,temp;
    int total;

    if (!call_other(cont, "can_put_and_get"))
        return 0;
    ob = first_inventory(cont);
    while(ob) {
        total++;
        temp = next_inventory(ob);
        move_object(ob, environment(cont));
        ob=temp; 
    }
    return total;
}

get() {
    return 1;
}

query_corpse() { return 1; }

query_weight() {
  if (decay < 2)
    return (level/8+10)*100;
  return (level/4+20)*100;
}

query_level() { return level; }

query_animal() { return animal; }
