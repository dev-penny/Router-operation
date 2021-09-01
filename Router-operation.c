#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>
#define INFINITY 9999
#define MAX 400
// Number of vertices in the graph
#define V 9

#include <stdio.h>
int total = 0;

int dijkstra2(int G[MAX][MAX], int n, int startnode, int target) {

	if (startnode == target)
		return 0;
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i, j;

	//pred[] stores the predecessor of each node
	//count gives the number of nodes 
	//create the cost matrix
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (G[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = G[i][j];

	//initialize pred[],distance[] and visited[]
	for (i = 0; i < n; i++) {
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}

	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;

	while (count < n - 1) {
		mindistance = INFINITY;

		//nextnode gives the node at minimum distance
		for (i = 0; i < n; i++)
			if (distance[i] < mindistance && !visited[i]) {
				mindistance = distance[i];
				nextnode = i;
			}

		//check if a better path exists through nextnode
		visited[nextnode] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i] < distance[i]) {
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}
	int index = 0;

	for (i = 0; i < n; i++)
		if ((i != startnode) && (i == target)) {
			// printf("\nDistance of node%d=%d",i,distance[i]);
			//  printf("\nPath=%d",i);

			j = i;

			int las = startnode;

			do {
				las = j;
				j = pred[j];
				//   printf("<-%d",j);

				if (j == startnode)
					//printf("LAST %d \n",las);
					return las;

			} while (j != startnode);
		}
}


struct packet {
	int routerno;
	int size;
	int cursize;
	int packetno;

	int flag;


};
struct router {
	int total;
	int id;
	int speed;
	int maxload;
	float pcload;
	struct packet *packs[1000];

	int G[MAX][MAX];
	int curpacks;
};
struct router *routers[1000];

struct packet * deletepacketfromrouter(int nop, int rp, int total) {
	int norouter = rp;
	printf("trying TO DELETE PACKET %d from %d \n", nop, rp);
	for (int i = 0; i <= routers[norouter]->curpacks; i++) {

		if ((routers[norouter]->packs[i]) != NULL) {

			printf("EINAI %d \n", routers[norouter]->packs[i]->packetno);
			if (routers[norouter]->packs[i]->packetno == nop) {
				///printf("delete FOUND PACK!\n");
				struct packet *p = routers[norouter]->packs[i];
				routers[norouter]->packs[i] = NULL;

				routers[norouter]->curpacks--;
				return p;

			}
		}
	}
	return NULL;
}
int addpackettorouter(struct packet *p, int rt) {

	int norouter = rt;
	printf("rt %d curpacks %d maxload %d packet no %d \n", rt,
			routers[norouter]->curpacks, routers[norouter]->maxload,
			p->packetno);
	if ((routers[norouter]->curpacks >= routers[norouter]->maxload))
		return 0;

	for (int i = 0; i <= routers[norouter]->curpacks; i++) {

		if ((routers[norouter]->packs[i]) == NULL) {

			routers[norouter]->packs[i] = p;
			routers[norouter]->curpacks++;
			printf("CHECK add %d to router %d having now %d packs \n",
					p->packetno, rt, routers[norouter]->curpacks);
			return 1;

		}

	}
	return 3;
}

int main() {
	printf("START \n");

	srand(time(NULL));

	//printf("Enter no. of vertices:");
	//scanf("%d", &n);

	int norouters = 0;
	printf("give me N number of routers:");
	scanf("%d", &norouters);


	int idno = 0;
	total = norouters;


	while (1) {
		int speed;
		int maxload;
		float pcload = 0;

		struct router *rt = (struct router*) malloc(sizeof(struct router));

		printf("id router %d \n", idno);
		printf("give me speed:");
		scanf("%d", &speed);
		rt->speed = speed;

		printf("give me mmaxload:");
		scanf("%d", &maxload);

		rt->maxload = maxload;
		rt->pcload = 0.0;

		rt->curpacks = 0;

		for (int k = 0; k <= 999; k++)
			rt->packs[k] = NULL;

		routers[idno] = rt;
		idno++;
		if (idno >= norouters)
			break;

	}
	printf("TOTAL %d \n", total);
	int G[MAX][MAX], i, j, u;
	printf("\nEnter the adjacency matrix:\n");  /*Pinakas geitniashs-dromologhshs p.x estw 5 routers o pinakas tha einai 5*5 : 
																	0 0 1 0 1 
																	0 0 1 0 1 
																	1 0 0 0 0 
																	1 1 1 0 0 
																	0 1 0 1 0  */
	

	for (i = 0; i < total; i++)
		for (j = 0; j < total; j++)
			scanf("%d", &G[i][j]);

	for (i = 0; i < total; i++)
		for (j = 0; j < total; j++) {
			if (i == j)
				G[i][j] = 0;
			else

				if (G[i][j] >= 1) {
					G[i][j] = routers[j]->maxload;

				}
		}

	for (i = 0; i < total; i++) {
		for (j = 0; j < total; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");

	}
	//exit(1);

	int t = 0;
	//while (u!=-1){
	printf("\nEnter the starting node:");
	scanf("%d", &u);
	printf("\nEnter the exiting node:");
	scanf("%d", &t);
	int sn = 0;

	//start creation of packages

	for (int rr = 0; rr < total; rr++)
		for (int ii = 0; ii < total; ii++) {
			for (int jj = 0; jj < total; jj++) {
				routers[rr]->G[ii][jj] = G[ii][jj];
				;
			}
		}

	int pk = 0;
	int ct = 0;
	int totalgiven = 0;
	int totalremain=0;
	while (1) {

		printf("time no %d \n\n\n", ct);

		//update flags
		for (int i = 0; i < total; i++) {

			for (int fp = 0; fp <= routers[i]->curpacks; fp++) {
				if (routers[i]->packs[fp] != NULL) {
					routers[i]->packs[fp]->flag = 1;
				}
			}
		}
		
		if (routers[u]->curpacks < routers[u]->maxload) {
			struct packet *cp = (struct packet *) malloc(sizeof(struct packet));
			printf("packet no %d \n", pk);

			cp->packetno = pk;

			int size = rand() % 3 + 1;

			cp->size = size;
			cp->cursize = size;
			cp->flag = 1;
			printf("inserting packet %d size %d\n", pk, size);

			addpackettorouter(cp, u);
			

			pk++;

		} else
			printf("Starting router %d MAX LOADED WITH current packs %d canno accept pack %d \n", u, routers[u]->curpacks,pk);

		//process packets for each router
		for (int s = 0; s < total; s++) {

			for (int curp = 0; curp <= routers[s]->curpacks; curp++) {
				struct packet *processp;

				processp = routers[s]->packs[curp];
				if (processp != NULL) {
					processp->cursize = processp->cursize - 1;
		            totalremain++;

				}

			}

			//process send packets for each router
			for (int s = 0; s < total; s++) {

				for (int curp = 0; curp <= routers[s]->curpacks; curp++) {
					struct packet *processp;

					processp = routers[s]->packs[curp];
					if ((processp != NULL) && (processp->cursize <= 0)
							&& (processp->flag == 1)) {

						int idpacket = processp->packetno;
						int apot;
						int count = 0;
						int prev = 0;
						while (1) {

							apot = dijkstra2(routers[s]->G, total, s, t);
							if ((routers[apot]->curpacks)>= (routers[apot]->maxload)) {

								printf("--- ROUTER %d is maxloaded to forward packet trying another\n",apot);
								prev = apot;
								count++;
								if (count >= 2) {
									for (int rr = 0; rr < total; rr++)
																		for (int ii = 0; ii < total; ii++) {
																			for (int jj = 0; jj < total; jj++) {
																				routers[rr]->G[ii][jj] = G[ii][jj];
																				;
																			}
																		}
									printf("--- BROKEN next move\n");
									break;

								}
								for (int rr = 0; rr < total; rr++)
									for (int ii = 0; ii < total; ii++) {
										for (int jj = 0; jj < total; jj++) {
											if ((ii == apot) || (jj == apot))
												routers[apot]->G[ii][jj] = 9999;
										}
									}

							} else {
								printf(" --- ROUTER %d is accepting package \n",
										apot);

								for (int rr = 0; rr < total; rr++)
									for (int ii = 0; ii < total; ii++) {
										for (int jj = 0; jj < total; jj++) {
											routers[rr]->G[ii][jj] = G[ii][jj];
											;
										}
									}
								break;

							}
						}

						struct packet *pp = (struct packet *) malloc (	sizeof(struct packet));
						pp->cursize = processp->size;
						pp->packetno = processp->packetno;
						pp->size = processp->size;
						pp->flag = 0;


						printf("forwarding packet %d size %d from %d to %d \n",
								pp->packetno, pp->cursize, s, apot);

						int ress = addpackettorouter(pp, apot);

						if (ress == 1) {

							struct packet* ap = deletepacketfromrouter(idpacket,
									s, total);
							if (ap != NULL) {

								printf(	"PACKetc %d Succesfully deleted from %d\n",	idpacket, s);

								processp->cursize = processp->size;

							
								printf(
										"PACKET %d IS TRANFERED FROM ROUTER %d to router %d \n", idpacket, s, apot);

								if (apot == t) {
									totalgiven++;
									printf("TOTAL GIVEN %d \n", totalgiven);

									printf("CONSUMING PACKET %d \n", idpacket);
									struct packet *apott =
											deletepacketfromrouter(idpacket, t,	total);
									if (apott != NULL) {
										printf("PACKET CONSUMED in %d\n", t);

									}

								}
							} else {
								printf(	"PAcket %d  UNsuccessfully deleted from %d = failed forwarding\n", idpacket, s);

							}

						} else {
							printf("FAILing to trasfer to router %d due to maxload \n",apot);

						}
					}

				}

			}

			//printf("apo %d pros %d APOT %d \n",s,t,apot);
		}

		//Average length of stay of each packet on the routers
		ct++;
		if (pk ==1000){


			printf("\n\n\n mean total remain in routers %f \n",(float)totalremain/pk);
			break;}
	}

	printf("HERE ends\n");


}

