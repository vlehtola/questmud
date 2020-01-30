cmd_event_beerrain(arg) 
{
 object list;
 int i, o, amount;
 string beerlist;

 list = users();

 if(!arg) 
   { 
    write("This requires an argument (amount of beers).\n"); 
    return 1; 
   }
 
	if(	this_player()->query_real_name() != "nalle" &&
		this_player()->query_real_name() != "walla" &&
		this_player()->query_real_name() != "astarel" &&
		this_player()->query_real_name() != "rag"
		&& this_player()->query_wiz() != 5
	   ) 
	{
	 write("No access.\n");
 	 return 0;
	}

  amount = to_int(arg);

  // Sanity
  if(amount < 1 ) amount = 1;
  if(amount > 50) amount = 50;

 for(o=0;o<sizeof(list);o++)
 { 
//  if(!list[o]->query_wiz())  
    {

     for(i = 0; i < amount; i++)
        {
         object bisse;
         bisse = clone_object("/wizards/walla/beer");
	 bisse -> init_beer();
         move_object(bisse, list[o]);
        }

    tell_object(list[o],"A choir of angels bursts into divine song and out of the blue,\n");
    tell_object(list[o],"summoned by "+this_player()->query_name()+", tossing around bottles of beer, FREE BEER! REJOICE!\n");

    if(amount == 1)
     tell_object(list[o], "A beer falls into your lap.\n");
	else
     tell_object(list[o], ""+amount+" beers fall into your lap.\n");
   } 
 }

 write("'Beer Rain' event started.\n");
 return 1;
}
