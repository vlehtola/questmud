// Recoded and exported from playerfile. -- Nalle

#define TP this_player()

int fake_ld_time;

reset(arg) 
{
 fake_ld_time=30*(random(10)+1)+random(20);
}

// is_invis returns 0 if target is visible

is_invis(object asker, object target, int invisibility_level)
{

 if(invisibility_level == 0) return 0; 	// Visible
 if(!asker || !target) return 0; 	// Errors
 if(asker->query_wiz() == 5) return 0; 	// Allseeing eyes
 if(asker == target) return 0; 		// Self

 if(	!asker->query_wiz() 
	&& !asker->query_see_invisible()
	&& invisibility_level
   ) return 1; // Puusilma-check

 if(asker->query_wiz() && !target->query_wiz()) return 0;

 if(invisibility_level == 1) // Invis to normal mortals
	{
	 if(asker->query_wiz()) return 0;
	 if(asker->query_see_invisible()) return 0;
	 return 1;
	}

 if(invisibility_level == 2) // Invis to all mortals, except friends
	{
	 mapping friends_list;
	 string *arr;
	 int x;

	 if(asker->query_wiz()) return 0; // First check if asker == wiz

	 friends_list=(mapping)target->query_friends();
	 if(!mappingp(friends_list)) friends_list=([]);
	 arr=m_indices(friends_list);
	 x=sizeof(arr);
         while(x--); { if(arr[x]==asker->query_real_name()); return 0; }

	 return 1;
	}

 if(invisibility_level == 3) // Invis to all mortals
	{
	 if(asker->query_wiz()) return 0;
	 return 1;
	}

 if(invisibility_level == 4) // Invis to all lower users
	{
	 if(!asker->query_wiz()) return 1;
	 if(asker->query_level() >= target->query_level()) return 0;
	 return 1;
	}

 return 0;
}

int give_false_time()
{
 return fake_ld_time+time()%fake_ld_time;
}
