int i;
object ob;
string arg,arg1;
get_time() {
    return 10-(this_player()->query_skills("speedcrafting")/12);
}
ep_cost() { return 10-(this_player()->query_skills("speedcrafting")/20); }
query_type() { return "witchcraft"; }

resolve_skill() {
    string room;
    room = file_name(environment(this_player()));
    i = this_player()->query_skills("search herbs");
    i += this_player()->query_skills("herbs knowledge");
    i = i/4;
    i = i+40+random(10);
    if (sscanf(room, "/room/out/%s#%s", arg,arg1) == 2) {
        if(i > random(110)) {
        get_herb(arg);
        return 1;
        }
        write("You find nothing.\n");
        return 1;
        }
write("This skill doesn't work here.\n");
return 1;
}
fail_skill() {
        tell_object(this_player(),"You fail the skill.\n");
        say(this_player()->query_name()+" fails the skill.\n");
        return 1;
}
get_herb(arg) {
        switch(arg) {
                case "plains":
                tell_object(this_player(), "You find a herb!\n");
                say(this_player()->query_name()+ " finds a herb.\n");
                ob = clone_object("/guilds/witch/obj/plain_herb.c");
                move_object(ob, environment(this_player()));
                ob->set_quality(i);
                break;
                case "dense_forest":
                tell_object(this_player(), "You find a herb!\n");
                say(this_player()->query_name()+ " finds a herb.\n");
                ob = clone_object("/guilds/witch/obj/dense_herb.c");
                move_object(ob, environment(this_player()));
                ob->set_quality(i);
                break;
                case "forest":
                tell_object(this_player(), "You find a herb.\n");
                say(this_player()->query_name()+ " finds a herb.\n");
                ob = clone_object("/guilds/witch/obj/forest_herb.c");
                move_object(ob, environment(this_player()));
                ob->set_quality(i);
                break;
                case "high_hills":
                tell_object(this_player(), "You find a herb.\n");
                say(this_player()->query_name()+ " finds a herb.\n");
                ob = clone_object("/guilds/witch/obj/high_herb.c");
                move_object(ob, environment(this_player()));
                ob->set_quality(i);
                break;
                case "swamp":
                tell_object(this_player(), "You find a herb.\n");
                say(this_player()->query_name()+ " finds a herb.\n");
                ob = clone_object("/guilds/witch/obj/swamp_herb.c");
                move_object(ob, environment(this_player()));
                ob->set_quality(i);
                break;
                case "hills":
                tell_object(this_player(), "You find a herb.\n");
                say(this_player()->query_name()+ " finds a herb.\n");
                ob = clone_object("/guilds/witch/obj/hills_herb.c");
                move_object(ob, environment(this_player()));
                ob->set_quality(i);
                break;
}
}
