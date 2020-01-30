#define CORPSE "/obj/corpse"
/*

   Changes for corpse by Nalle on 050602
  
   This object is a standard food object and works
   like /obj/alco_drink.c or /obj/armour.c
  
   To use this you can do:
     inherit "/obj/food";
   ......
   or,
   object ob;
   ob = clone_object("obj/food");
   ob->set_name("apple pie");
  
*  For more documentation look at /doc/build/food


   These functions are defined:

           set_name(string)     To set the name of the item. For use in id().

   Two alternative names can be set with the calls:

           set_alias(string) and set_alt_name(string)

           set_short(string)    To set the short description.

           set_long(string)     To set the long description.

           set_value(int)       To set the value of the item.

           set_weight(int)      To set the weight of the item.

           set_strength(int)    To set the healing power of the item. If you
                                don't wish the item to have healing powers
                                just set this value to 0.

           set_eater_mess(string)
                                To set the message that is written to the 
                                player when he eats the item.

           set_eating_mess(string)
                                To set the message given to the surrounding
                                players when this object is eaten.


        For an example of the use of this object, please read:
*       /doc/examples/apple_pie.c

*/

string name, short, long, eating_mess, eater_mess, alias, alt_name;
int value, strength, weight, poison;

init()
{
        add_action("eat", "eat");
}

reset(arg) {
        if (arg)
                return;

        weight = 1; 
        eater_mess = "You eat "+short()+".\n";
        eating_mess = " eats "+short()+".\n";
}

prevent_insert()
{
  write("You don't want to ruin " + short + ".\n");
  return 1;
}

id(str)
{
        return  str == name || str == alt_name || str == alias;
}

short() {
        if(!short)
            return name;
        return short;
}

long() 
{
        if(!long)
                write(short() + ".\n");
        else
                write(long);
}

get()
{
        return 1;
}

eat(str) {
        object tp,ob;
        string tmp;

        tp = this_player();

        if (!str) {
          write("Eat what?");
          return 1;
        }
        if(this_object() != present(str) && str != "all") {
          return;
        }
        eater_mess = "You eat "+short()+".\n";
        eating_mess = " eats "+short()+".\n";
        write(eater_mess);
        if (eating_mess)
                say(capitalize(this_player()->query_name()) + eating_mess);
        else
                say(capitalize(this_player()->query_name()) + " eats " + short + ".\n");
        tp->eat_food(strength);

       // If is corpse
       if(sscanf(file_name(this_object()), CORPSE+"%s", tmp) == 1) {
         if(!query_animal()) {
          write("You feel your soul tainted by the ruthless deed.\n");
          this_player()->add_alignment(-3);
                             }
         //Autoextract possible objects from the corpse
         ob=this_object();
         CORPSE->autoextract_obj(ob);
        }
        if (poison) { 
                write("The food tastes somehow strange.\n");
                this_player()->set_poison(1);
        }
        move_object(this_object(),environment(this_player()));
        this_player()->fix_weight();
        destruct(this_object());
        return 1;
}

set_poison(i) {
    poison = i;
}

min_cost()
{
        return 4 * strength + (strength * strength) / 10;
}

set_name(n) 
{ 
        name = n; 
}

set_short(s) { 
  short = s; 
}

set_long(l) 
{ 
        long = l; 
}

set_value(v) 
{ 
        value = v; 
}

set_weight(w) 
{ 
        weight = w; 
}

set_strength(s) 
{
        strength = s; 
}

set_alias(a) 
{ 
        alias = a; 
}

set_alt_name(an) 
{ 
        alt_name = an; 
}

set_eating_mess(em) 
{ 
        eating_mess = em; 
}

set_eater_mess(em) 
{ 
        eater_mess = em; 
}

/*
 * Things that other objects might want to know.
 */

query_value() 
{ 
        if (value)
                return value; 
        else
                return min_cost();
}

query_weight() 
{ 
        return weight; 
}
