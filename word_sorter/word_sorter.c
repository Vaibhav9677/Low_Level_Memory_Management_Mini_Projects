
/*
	-Name : Vaibhav Pawar
	-Roll No : 24112023

	-Problem Statement : Given n words in memory sort them in alphabetical order

	-user interface 
		- input shall given in memory
		- each word having space after as seperator
		- after giving all word enter one '\0' at the end 
		- memory size 4096(4 KB) 1 byte is 8bit long
		- Bytes : numbeed from left to right (0 - (n-1))
		- 
			+--------------------------------------------------------------------------------+
			| | | | | | | | | | | | | ---------------------------------------| | | | | | | | |
			+--------------------------------------------------------------------------------+
			0 1 2 3 --------------------------------------------------------(n-4)(n-3)(n-2)(n-1)


		- n = 4096
		- Bits : Numbered form right to left 
			+--------------+
			| | | | | | |  |
			+--------------+
			7 6 5 4 3 2 1 0
			
		- user can any length of word and length of the sequance of word is n-14 byte include the '\0'

*/

#include<stdio.h>

#define len 0xFFFF     					  // Total size of memory 

#define m *((unsigned short int *)&mem[len-2])         // temporary point to first word
#define n *((unsigned short int *)&mem[len-4])		   // temporary point to first word
#define p *((unsigned short int *)&mem[len-6])		   // point to the next charater to swap
#define fw *((unsigned short int *)&mem[len-8])		   //point to first word
#define sw *((unsigned short int *)&mem[len-10])	   //point to second word
#define temp *((unsigned char *)&mem[len-11])		   // store character for swaping 
#define flag *((unsigned char *)&mem[len-12])		   // flag to see word swap or not


int main()
{
	unsigned char mem[len] = {"sure! seres a block of 2000 random words separated by spaces: apple banana chair river mountain cloud orange bottle window paper light shadow music garden tree phone table ocean star door stone moon flower clock road book pencil sun glass rain fire bird dog cat fish house sky water bridge lamp coffee tea hat car train boat key shirt mirror camera watch field hill forest beach valley night day energy color voice dream sound heart smile laugh hand foot eye ear hair face finger wall floor ceiling roof path street door handle cup plate fork spoon knife pan stove oven fridge shelf pillow blanket bed chair sofa television computer laptop keyboard mouse speaker wire plug screen battery button switch remote bag pen ruler notebook sketch paint brush canvas art statue sculpture photo film song dance theater game sport ball bat racket goal net stadium team player coach referee judge rule card dice toy puzzle chess move strategy code number equation formula graph chart data list map compass GPS travel ticket passport visa flight airport bus station taxi ride bicycle helmet jacket shoes socks belt ring necklace bracelet gift surprise party cake candle balloon holiday festival event wedding birthday anniversary meeting appointment deadline schedule calendar clock alarm timer stopwatch second minute hour day week month year century history story novel poem script dialogue character role actor actress director producer audience critic review rating scene plot theme genre mystery thriller horror comedy drama romance fantasy adventure action sci-fi superhero villain hero power magic spell wand potion dragon castle knight sword shield army war peace treaty law order crime detective police jail prison escape chase fight battle explosion gun bullet bomb missile tank ship submarine satellite planet space galaxy universe star meteor comet eclipse orbit gravity rocket astronaut alien robot android cyborg chip circuit wire signal transmission frequency radio wave sound echo vibration noise silence speech language word letter alphabet dictionary translation communication message email text call chat social media website internet browser link page post comment like share follow friend group community forum discussion debate opinion fact truth lie secret mystery code encryption security password lock unlock access permission restriction firewall antivirus malware virus trojan spyware hacker attack breach identity privacy account username profile photo bio status update feed notification alert warning danger risk accident emergency rescue help support guide tutorial lesson class course subject exam test quiz score grade pass fail repeat study learn teach professor student school college university degree diploma certificate job career profession work office business company organization corporation industry economy market trade stock investment finance bank loan credit debit wallet cash card coin price cost value profit loss income expense budget tax bill receipt invoice contract agreement deal negotiation partnership customer client buyer seller shop store mall outlet supermarket grocery restaurant menu order food drink dish meal breakfast lunch dinner snack recipe ingredient kitchen cook chef waiter delivery tip review star rate service quality quantity option choice preference taste flavor sweet sour bitter salty spicy bland hot cold fresh frozen canned organic natural artificial processed raw grilled fried baked boiled steamed roasted smoked fermented preserved aged expired rotten moldy stale dirty clean dry wet liquid solid gas plasma matter atom molecule element compound chemical reaction formula equation experiment research lab scientist engineer inventor innovation technology device machine tool equipment instrument component material resource energy power electricity fuel battery solar wind nuclear hydrothermal geothermal renewable sustainable environment climate weather season spring summer autumn winter cold warm hot humid dry fog mist cloud rain drizzle shower storm thunder lightning flood drought snow ice frost hail blizzard tornado hurricane cyclone typhoon tsunami earthquake landslide avalanche eruption volcano lava magma ash dust smoke pollution waste garbage trash recycle reuse reduce dispose landfill dump compost soil ground grass plant seed root stem leaf flower fruit vegetable tree forest jungle park garden farm field harvest crop grain rice wheat corn barley oats beans peas lentils nuts berries grapes apple orange banana mango pineapple coconut watermelon melon peach plum cherry strawberry raspberry blueberry blackberry fig date olive lemon lime grapefruit pomegranate guava kiwi papaya passionfruit dragonfruit lychee jackfruit durian bread butter cheese milk yogurt cream ice cream chocolate candy sugar honey syrup jam jelly peanut almond cashew walnut hazelnut pecan macadamia pistachio sesame sunflower pumpkin flax chia hemp protein vitamin mineral fiber carbohydrate fat calorie diet health exercise fitness sport gym yoga meditation relaxation sleep dream nightmare fantasy reality illusion imagination creativity inspiration motivation goal success achievement failure mistake lesson challenge opportunity risk reward plan strategy decision action result consequence impact influence change growth progress development evolution revolution transformation innovation invention discovery experiment analysis observation measurement calculation estimation prediction assumption hypothesis theory law principle concept idea thought opinion perspective viewpoint belief value ethic morality justice fairness equality freedom rights responsibility duty obligation rule regulation policy law enforcement government democracy republic monarchy dictatorship communism socialism capitalism anarchism nationalism globalism patriotism rebellion protest strike boycott revolution conflict war peace harmony balance unity diversity inclusion equity respect tolerance acceptance kindness empathy compassion friendship love relationship marriage family child parent sibling cousin relative ancestor generation heritage tradition culture language dialect accent expression gesture habit behavior routine custom ritual festival holiday celebration ceremony anniversary birthday wedding funeral memory history past present future time space dimension parallel universe alternate reality simulation virtual reality game puzzle riddle enigma mystery clue detective investigation evidence proof fact fiction fantasy science fiction horror thriller adventure action drama comedy romance tragedy hero villain character protagonist antagonist role actor actress director script dialogue monologue speech voiceover narration documentary animation cartoon series movie show episode season pilot premiere finale cliffhanger plot twist storyline arc theme moral lesson message meaning symbol metaphor analogy comparison contrast paradox irony sarcasm humor joke pun wit satire parody spoof reference homage tribute remake reboot adaptation inspiration influence origin source version sequel prequel spin-off crossover collaboration partnership teamwork unity cooperation assistance support help aid guidance leadership mentorship coaching training education knowledge wisdom intelligence intellect mind brain thought emotion feeling mood attitude behavior personality character trait quality skill ability talent gift strength weakness flaw fear phobia anxiety stress depression happiness joy excitement enthusiasm curiosity interest passion ambition determination persistence perseverance resilience courage bravery heroism adventure exploration discovery journey travel trip vacation tour expedition mission quest challenge test trial competition contest game match round level stage checkpoint milestone goal objective target achievement success reward prize trophy medal certificate diploma degree qualification career job profession work employment business industry market trade stock economy finance banking investment property real estate housing apartment house home mortgage rent lease contract agreement deal negotiation transaction payment salary wage income revenue profit loss expense cost budget tax bill receipt invoice debt loan credit debit card wallet purse pocket bank account savings deposit withdrawal transfer transaction statement balance fee charge fine penalty lawsuit court trial judge jury lawyer attorney defendant plaintiff witness testimony evidence proof fact truth justice fairness equality freedom rights responsibility duty obligation law order rule regulation policy government authority power control influence leadership management organization administration system structure framework institution agency department committee board council panel commission association union group community society culture tradition heritage history past present future time space reality existence universe galaxy star planet sun moon earth world life nature environment climate weather season day night light dark shadow reflection mirror glass window door wall floor ceiling roof building architecture structure design style form shape pattern texture color contrast harmony balance symmetry proportion scale perspective depth dimension direction angle position location distance measurement calculation estimation prediction assumption hypothesis theory logic reasoning argument debate discussion conversation dialogue speech language communication expression gesture symbol sign letter word phrase sentence paragraph text document file record data information knowledge intelligence mind brain thought idea concept notion opinion perspective viewpoint belief value ethic morality principle rule standard guideline norm custom habit behavior action reaction response decision choice option alternative possibility opportunity risk reward challenge difficulty problem solution answer explanation clarification understanding learning education teaching training coaching mentorship guidance leadership inspiration motivation ambition determination persistence perseverance resilience courage bravery confidence skill ability talent gift strength weakness limitation fear anxiety stress pressure tension relaxation peace calm tranquility harmony balance stability security safety protection defense shelter refuge sanctuary escape freedom independence autonomy control power influence authority leadership management organization administration system structure framework network connection relationship association bond link interaction collaboration cooperation teamwork partnership unity community society culture tradition heritage history past present future time space reality existence being identity self-awareness consciousness perception sensation feeling emotion mood attitude behavior personality character trait quality attribute feature aspect element component material substance object thing entity item unit part piece section segment fragment division category classification type kind sort variety range scale level degree extent measure quantity amount number count digit figure value price cost expense budget finance economy trade market industry business company organization corporation institution agency department committee board council panel commission association union club group team party movement campaign protest strike revolution conflict war battle fight struggle competition rivalry challenge contest match game sport activity exercise practice training workout hobby interest passion ambition goal dream vision mission purpose meaning reason cause effect result outcome impact consequence influence change transformation evolution progress development growth improvement advancement achievement accomplishment success victory win loss failure mistake error fault flaw weakness limitation disadvantage problem difficulty obstacle barrier restriction constraint limitation condition requirement necessity essential priority preference choice option alternative possibility opportunity risk reward benefit advantage profit gain incentive motivation inspiration drive enthusiasm excitement joy happiness satisfaction fulfillment contentment peace harmony balance stability security safety protection defense survival existence reality being identity self-awareness consciousness perception sensation feeling emotion mood attitude behavior personality character trait quality attribute feature aspect element component material substance object thing entity item unit part piece section segment fragment division category classification type kind sort variety range scale level degree extent measure quantity amount number count digit figure value price cost expense budget finance economy trade market industry business company organization corporation institution agency department committee board council panel commission association union club group team party movement campaign protest strike revolution conflict war battle fight struggle competition rivalry challenge contest match game sport activity exercise practice training workout hobby interest passion ambition goal dream vision mission purpose meaning reason cause effect result outcome impact consequence influence change transformation evolution progress development growth improvement advancement achievement accomplishment success victory win loss failure mistake error fault flaw weakness limitation disadvantage problem difficulty obstacle barrier restriction constraint limitation condition requirement necessity essential priority preference choice option alternative possibility opportunity risk reward benefit advantage profit gain incentive motivation inspiration drive enthusiasm excitement joy happiness satisfaction fulfillment contentment peace harmony balance stability security safety protection defense survival existence reality being identity self-awareness consciousness perception sensation feeling emotion mood attitude behavior personality trait quality attribute feature aspect element component material substance object thing entity item unit part piece section segment fragment division category classification type kind sort variety range scale level degree extent measure quantity amount number count digit figure value price cost expense budget finance economy trade market industry business company organization corporation institution agency department committee board council panel commission association union club group team party movement campaign protest strike revolution conflict war battle fight struggle competition rivalry challenge contest match game sport activity exercise practice training workout hobby interest passion ambition goal dream vision mission purpose meaning reason cause effect result outcome impact consequence influence change transformation evolution progress development growth improvement advancement achievement accomplishment success victory win loss failure mistake error fault flaw weakness limitation disadvantage problem difficulty obstacle barrier restriction constraint limitation condition requirement necessity essential priority preference choice option alternative possibility opportunity risk reward benefit advantage profit gain incentive motivation inspiration drive enthusiasm excitement joy happiness satisfaction fulfillment contentment peace harmony balance stability security safety protection defense survival existence reality being identity self-awareness consciousness perception sensation feeling emotion mood attitude behavior personality character trait quality attribute feature aspect element component material substance object thing entity item unit part piece section segment fragment division category classification type kind sort variety range scale level degree extent measure quantity amount number count digit figure value price cost expense budget finance economy trade market industry business company organization corporation institution agency department committee board council panel commission association union club group team party movement campaign protest strike revolution conflict war battle fight struggle competition rivalry challenge contest match game sport activity exercise practice training workout hobby interest passion ambition goal dream vision mission purpose meaning reason cause effect result outcome impact consequence influence change transformation evolution progress development growth improvement advancement achievement accomplishment success victory win loss failure mistake error fault flaw weakness limitation disadvantage problem difficulty obstacle barrier restriction constraint limitation condition requirement necessity essential priority preference choice option alternative possibility opportunity risk reward benefit advantage profit gain incentive motivation inspiration drive enthusiasm excitement joy happiness satisfaction fulfillment contentment peace harmony balance stability security safety protection defense survival existence reality being identity self-awareness consciousness perception sensation feeling emotion mood attitude behavior personality trait quality attribute feature aspect element component material substance object thing entity item unit part piece section segment fragment division category classification type kind sort variety range scale level degree extent measure quantity amount number count digit figure aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaza zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz zasa zabc \0 "};
	printf("unsorted : %s\n\n",mem);

	m = 0;
	n = 0;
	p = 0;
	fw = 0;
	sw = 0;

	while(mem[fw] != 0x0)				// check the sequance word end or not  run till get '\0'	
	{
		sw = fw;

		while(mem[sw] != 0x20)				//go to the next word form frist word
		{
			sw = sw + 1;
		}
        	sw = sw + 1;
		
		while(mem[sw] != 0x00)           //compare one to all remainings words
		{	
			m = fw;
			n = sw;
			flag = 0;

			while(flag != 1)  				// if flag set 1 then word swaped at privous ietration
			{
				if(mem[m] > mem[n])         //check first word is greater than second word
				{
					m = fw;
					n = sw;
					p = n;

					while(mem[p] != 0x20)     				//forward bigger word one by one
					{
						temp = mem[n];
						p = n;
						n = n + 1;

						while(p != m)
						{
							mem[p] = mem[p-1];
							p = p -1;
						}

						mem[m] = temp;
						m = m +1;
					}

					sw = n;
					flag = 1;
				}
				else if(mem[m] == mem[n])					//check next character if two are equal
				{
					m = m + 1;
					n = n + 1;

					if(m == sw)
					{
						flag = 1;							//it two word are equal not swap
						sw = n;
					}
				}
				else if(mem[m] < mem[n])					//first word is less than second 
				{
					while(mem[n] != 0x20)					//go to next word
					{
						n =  n + 1;	
					}

					n = n + 1;
					sw = n;
					flag = 1;
				}
			}
		}

		while(mem[fw] != 0x20)       //compare next word 
		{
			fw = fw + 1;	
		}

		fw = fw + 1;
	}
	
	printf("Sorted :%s\n",mem);   

	return 0;
}
