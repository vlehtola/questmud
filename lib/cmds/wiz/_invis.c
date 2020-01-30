// -- Nalle

#define TP this_player()

cmd_invis(string str) 
{
 int invis;

   if(!str)
     {
	 write( "Your invisibility level is "+TP->query_invisibility_level()+
		", you are ");

	 switch(TP->query_invisibility_level()) 
	{
	 case  0: write("visible.\n"); return 1;
	 case  1: write("normally invisible.\n"); return 1;
	 case  2: write("visible to friends and wizards.\n"); return 1;
	 case  3: write("invisible to all mortals.\n"); return 1;
	 case  4: write("invisible to lower users.\n"); return 1;
	}
     }

 switch(str) 
	{
	case "0"	: invis=0;
			  write("You are now visible.\n");
			  break;

	case "1" 	: invis=1;
			  write("You are now invisible to most mortals.\n");
			  break;

	case "2"	: invis=2;
			  write("You are now invisible to all mortals, "+
			  "but available to friends.\n");
			  break;

	case "3"	: invis=3;
			  write("You are now invisible to all mortals.\n");
			  break;

	case "4"	: invis=4;
			  write("You are now invisible to all lower users.\n");
			  break;

	default		: write("Syntax : invis < 1 - 4 >\n");
			  return 1;
	}


 this_player()->set_invisible(invis);
 return 1;
}
