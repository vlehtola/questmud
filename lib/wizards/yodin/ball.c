inherit "obj/armour" /*osaataan*/

start() {
      set_short("A magic ball");     
      set_alias("ball");
      set_long("An offical magic ball! throw <player> or kick <player>.\n");
   }


int drop_object(string str) {

    if (str == "all") {
/*m�r�k�lli sy� sinut*/
/*no ei oikeasti*/
        drop_object("magic ball");
        return 0;
    }
    if (environment() != this_player()) return 0;
    write("The magic ball explodes when it hits the ground!\n");
    say(this_player()->query_name() + " drops a magic ball, which explodes into a million pieces.\n");                                                           
    destruct(this_object());
    return 1;
}

int throw(string str) {
    object ob;

    if(!str) return 0;
    ob = find_player(lower_case(str));
    if(!ob) {
        write("The ball is confused. It cannot find that person.\n");
        write("That person is not playing right now!\n");
        return 1;
    }
   
    if(!present("magic ball",ob)) {
       write("You throw the magic ball to " + capitalize(str) + ".\n");
       move_object(this_object(),ob);
       tell_room(environment(ob),"You see a magic ball flying through the air.\n" +
                     "The magic ball is swiftly thrown to " +
                     capitalize(str) + " by " + this_player()->query_name() + ".\n" +
                     capitalize(str) + " jumps into the air and catches it.\n"); 
       tell_object(ob, "A magic ball thrown by " + this_player()->query_name() + " lands in your arms.\n");
      return 1;
    }
}

int kick(string str) {
    object ob;

    if(!str) return 0;
    ob = find_player(lower_case(str));
    if(!ob) {
        write("The ball is confused. It cannot find that person.\n");
        write("That person is not playing right now!\n");
         return 1;
    }

    if(!present("magic ball",ob)) {
        write("You kick the magic ball to " + capitalize(str) + ".\n");
        move_object(this_object(),ob);
        tell_room(environment(ob),"A magic ball kicked by " + this_player()->query_name() + " flies over your "+
                      "head on its way to " + capitalize(str) + ".\n" +
                      capitalize(str) + " leaps into the air and " +
                      "catches the magic ball with one hand!\n");
        tell_object(ob, "A magic ball kicked by " + this_player()->query_name() + " lands in your arms.\n");
       return 1;
    }
 }  

init(){
     add_action("throw","throw");
     add_action("kick","kick");
     add_action("drop_object","drop");
}                                   
