inherit "room/room";
string player;
string th_player;
int exits;
object ob;

int x=1;
int a;
#define HITS "/wizards/luminarc/spec/hits.c"
#define SIGN "/wizards/luminarc/spec/sign.c"
#define ROOM "/wizards/luminarc/spec/snow"
reset(arg) {
  if(arg) return;
  short_desc = "Startroom";
  long_desc = "This is a room where you can join a snowball event.\n"+
              "Look at the sign for more information\n";
  property = allocate(1);
  set_light(3);
  ob=clone_object("/wizards/luminarc/spec/kylt");
  move_object(ob, this_object());
  add_exit("portal","/world/city/cs");
}

init() {
  ::init();
  add_action("join", "join");
  add_action("who_event", "who_event"); 
  add_action("start_event", "start_event");  
}

reset_all()
{
call_other(HITS,"reset_hit_me");
call_other(HITS,"reset_my_map");
call_other(HITS,"reset_check_hits");
call_other(HITS,"reset_event_player");
return 1;
}

who_event(str)
{
check_players();
return 1;
}
join(str) {
  if(str == "event") {
        player = this_player()->query_name();
        exits = check_join(player);
        if (exits == 0)
        {
        call_other(SIGN, "sign_up", player);
        write("You join the snowball event.\n");
        x = call_other(SIGN, "how_many_players");
        x--;
        write("There is " + x + " players on snowball event.\n");
        player = call_other(SIGN, "query_event_player", x);
        check_players();
        exits = 1;
        }
        else { write("But you have already signed up!\n"); }
        return 1; /* stop the execution */
        
   }

}
check_join(string name)
{
        a = call_other(SIGN, "how_many_players");
        
        for (x=1;x<a;x++)
        {
                th_player = call_other(SIGN, "query_event_player", x);
                if (x < 0)
                        break;
                 if (x > 10)
                        break;
                if (th_player == name)
                        return 1;        
}       
}
check_players()
{
        a = call_other(SIGN, "how_many_players");
        write("Players currently at event:\n");
        for (x=1;x<a;x++)
        {
                player = call_other(SIGN, "query_event_player", x);
                write(player + "\n");
                if (x < 0)
                        break;
                if (x > 10)
                        break;
        }
return 1;
}
start_event()
{
tell_players();
call_out("snowball", 10);
}
tell_players()
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
                tell_object(ob, "Event is starting in 10 seconds\n");
        }

}

snowball()
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
                if (a < 3)
                        {
                        ob=find_player(player);
                        tell_object(ob, "Not enough players to play.\n");
                        return 1;
                        reset_all();
                        }
                else {
                ob=find_player(player);
                move_object(ob, ROOM);
                command("look",ob);
                tell_object(ob, "Event has been started. Good luck!\n");
                }
} 
        
}
