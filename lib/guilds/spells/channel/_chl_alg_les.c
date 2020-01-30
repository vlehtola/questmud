// Align spells - Nalle 04/2003

#define TP this_player()

#define ALIGN_CHANGE (TP->query_wis() / 10)

resolve(bonus, target) 
{
 object ob;
 int time, abs;
 ob = present(target, environment( TP ));

 if(!ob) 
 {
  write("There is no one called "+ capitalize(target) +" here.\n");
  return 1;
 }

 if(ob == TP)
 {
  write("You cannot alter your own alignment with this spell.\n");
  return 1;
 }

 time = bonus+30+ (TP->query_level() / 10);

 // Generic messages
 say(	TP->query_name()+" performs a ceremony, attempting to alter "+
	capitalize(target)+"'s alignment.\n", ({ TP, ob }) );
 write("You attempt to alter "+capitalize(target)+"'s alignment.\n");
 tell_object(ob, TP->query_name()+" performs a ceremony, attempting to "+
		 "change your alignment.\n");

 // A message to the target about if it worked
 abs=ALIGN_CHANGE; if(abs<0) abs*=-1; // A positive integer

 if(!abs) 
   {
    tell_object(ob, "For some reason, you feel exactly the same.\n");
   }
   else
   {
    tell_object(ob, "You feel more "+good_or_bad()+".\n");
   }

 if(TP->query_tester() || TP->query_wiz()) write("Tester-info : "+ALIGN_CHANGE+"\n");
 ob->hard_add_alignment( ALIGN_CHANGE );
 return 1;
}

/****************************/

string good_or_bad() 
{
if (ALIGN_CHANGE>0) 	return "benevolent";
   else
			return "malevolent";
}
