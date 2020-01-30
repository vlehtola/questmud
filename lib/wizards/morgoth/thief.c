inherit "/obj/monster";
 
reset() {
 ::reset();
 set_name("thief");
 set_short("A sneaky little thief...");
 set_long("This is an invisible thief. If you are reading this,\n"+
          "something is wrong because you can see him.\n");
 set_level(20);
 set_str(20);
 set_con(20);
 set_al(-100);
 money = 500+random(100);
}
 
 
init()
{
::init();
call_out("scan_players",5);
}
 
object tar;
 
scan_players()
{
object p;
 
remove_call_out("scan_players");
p=present("player\nid");
if(!environment(this_object())->no_fight())
if(p) {
   tar=p;
   call_out("glare",2);
   tell_object(tar,"You feel vaguely uncomfortable, like you're being watched.\n");
   return;
   }
 
call_out("scan_players",5);
}
 
glare()
{
int money_taken;
 
remove_call_out("glare");
call_out("scan_players",5);
if(environment(tar)!=environment(this_object()))return;
if(environment(this_object())->no_fight()) return;
if(tar->query_level()>=40) {
   tell_object(tar,"You catch the thief's hand!  He looks guilty.\n");
   return;
   }
 
if(tar->query_level()<5) {
   tell_object(tar,"Someone sneaks away in disdain!\n");
   }
 
tell_object(tar,"Your purse feels lighter!\n");
money_taken=tar->query_money()/2;
if(money_taken>3000)money_taken=3000;
tar->add_money(-money_taken);
return;
}
