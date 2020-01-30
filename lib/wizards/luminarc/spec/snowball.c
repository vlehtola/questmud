#define SNOWBALL_D "/wizards/luminarc/spec/hits.c"
#define STARTROOM  "/wizards/luminarc/spec/start.c"
#define SIGN       "/wizards/luminarc/spec/sign.c"
int how_many_players;
int a;
string player;
int x;
int y;
string name;
object who;
object ob;
object ob2;
reset(arg) {
  if(arg) return;
}
id(str) {
  return str == "snowball";
}
get() {
  return 1;
}
query_weight() {
  return 100;
}
short() {
  return "Small snowball";
}
long() {
  write("Small snowball.\n");
}
init() {
  add_action("throw", "throw");
}

reset_all()
{
call_other(SNOWBALL_D,"reset_hit_me");
call_other(SNOWBALL_D,"reset_my_map");
call_other(SNOWBALL_D,"reset_check_hits");
call_other(SNOWBALL_D,"reset_event_player");
return 1;
}


throw(str) {
object ob;
string what;
name = this_player()->query_name();
if (!str)
{
        return 1;
}

  if (!str)
        return 0;
    if (environment() != this_player()) {
        write("You must have snowball.\n");
        check_ld();
        return 1;
    }
    if (id(str) || sscanf(str, "snowball at %s", what) != 1) {
        write("Throw snowball on who?\n");
        check_ld();
        return 1;
    }
    ob = present(what, this_player());
    if (!ob)
        ob = present(what, environment(this_player()));
    if (!ob)
        {
        write("There is no "+ what + " in here\n");
        return 1;
}
 if (!living(ob)) {
 write("You can only throw balls at living things!\n");
 return 1;
}
 if (living(ob)) {
          name = this_player()->query_name();
          name = lower_case(name);

          if (what == name)
                {
                        write("You cannot throw yourself\n.");
                        return 1;
                }
        else {}
        name = this_player()->query_name();
        write("You start aiming snowball to the " + what + ".\n");
        x=random(100);
        write("You throw the snowball to the " + what + "\n");
        if(x<60)
        {
        write("And HIT!\n");
        call_other(SNOWBALL_D, "snowball_hit", name);
        who=find_player(what);
        tell_object(who, "Snowball HITS you on the face.\n");
        call_other(SNOWBALL_D, "hit_me", what);
        y=call_other(SNOWBALL_D, "check_hits", what);
        check_status(y, what, name);
        }
        else { write("But MISS!\n"); }
        destruct(this_object());
        return 1;

    }
    return 0;

}
check_ld()
{
a = call_other(SIGN, "how_many_players");
for (x=1;x<a;x++)
        {
                player = call_other(SIGN, "query_event_player", x);
                if (x < 0)
                        break;

                if (x > 10)
                        break;

                player=lower_case(player);
                ob=find_player(player);
                if(!ob)
                        call_other(SIGN,"reduce_players");
                if(ob->query_link_dead()==1)
                        call_other(SIGN,"reduce_players");
player = this_player()->query_name();
player = lower_case(player);
check_who(player);

}
}
check_status(int times, string name, string thrower)
        {
        check_ld();
        if(times>4)
                {
                ob=find_player(name);
                tell_object(ob, "You have 5 or more hits on you. You are removed from game\n");
                shout(name+" is removed from snowball fight!\n");
                call_other(SIGN, "reduce_players");
                check_who(thrower);
                move_object(ob, STARTROOM);
                return 1;
                }
        if(times<4)
                {
                ob=find_player(name);
                return 1;
                }
        }
check_who(string play) {
	int award;
how_many_players=call_other(SIGN, "how_many_players");
if (how_many_players < 3)
        {
        play = lower_case(play);
        ob2 = find_player(play);
        award = (random(5)+1)*random(1000000);
        shout("The snowball events is over and winner is "+name+" and the award is "+award+" experience points!\n");
        ob2->add_exp(award);
        move_object(ob2, STARTROOM);
        reset_all();
        call_other("/world/city/cs", "remove_exit", "portal");
        }
return 1;
}
