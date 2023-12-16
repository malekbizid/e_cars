#include <stdio.h>
#include <string.h>
struct date
{int j,m,a;
};

struct voiture
{
    char nom_du_client[50];
    char clientid[13];
    char modelevoiture[20];
    char marquevoiture[20];
    int n,loyer,jours,locationdevoitureparjour;
    struct date datelouer,dateretour;
    char etat[20];
};
char marque_de_voiture[10][20]={"NISSAN","FIAT","HONDA","TOYOTA","FORD","ALPHA ROMEO","MERCEDES","AUDI","BMW","OPEL"};
char modele_de_voiture[10][20]={"Juke","600","Civic","Avalon","Cobra","Stelvio","Class A","A6","X","Astra"};
int location_voitureparjour[10]={250,150,200,250,150,200,300,350,350,200};
int z=0,u=0;
struct voiture c,ca,cr[10];
void catalogue()
{
    int i ;
    printf("###############NOTRE CATALOGUE################## \n");
    printf("#    MARQUE   #   MODELE # locationvoitureparjour # \n");
    for(i=0;i<10;i++){
        printf("#   %s  #%s   # %d   #\n",marque_de_voiture[i],modele_de_voiture[i],location_voitureparjour[i]);
        
    };
}
int date_diff(int a1,int a2,int m1,int m2,int j1,int j2)
{
    int jours;
    if (a1!=a2) 
        jours=(a2-a1-1)*360+(12-m1-1)*30+(m2-1)*30+30-j1+j2;
        
    else if (m2!=m1) 
        jours=(m2-m1-1)*30+(30-j1)+j2;
    else 
      {
       jours=j2-j1 ;
      };
        return jours;

}
void louer_voiture()
{
    int i,f1,f2;
    int t;
    char ch;
    int j,x,r;
    printf("BIENVENUE CHER CLIENT! \n");
    catalogue();
    printf("ENTREZ LA MARQUE DE LA VOITURE QUE VOUS SOUHAITEZ LOUER: ");
    scanf("%s",c.marquevoiture);
    printf("ENTREZ LE MODELE QUE VOUS SHOUAITEZ LOUER:  ");
    scanf("%s",c.modelevoiture);
    printf("INDIQUEZ LA DATE A LAQUELLE VOUS PRENDREZ LA VOITURE (jj mm aaaa): ");
    scanf("%d%d%d",&c.datelouer.j,&c.datelouer.m,&c.datelouer.a);
    printf("INDIQUEZ LA DATE A LAQUELLE VOUS RESTITUEREZ LA VOITURE(jj mm aaaa): ");
    scanf("%d%d%d",&c.dateretour.j,&c.dateretour.m,&c.dateretour.a);
    printf("VERIFIONS SI LA VOITURE EST DISPONIBLE \n");
    FILE *ptr;
    ptr=fopen("louer_voiture.txt","r");
    
    for (j = 0; c.modelevoiture[j]!='\0'; j++) {   

        if(c.modelevoiture[j] >= 'a' && c.modelevoiture[j] <= 'z') 
            {
                c.modelevoiture[j] = c.modelevoiture[j] -32;
            }
         }
          for (j = 0; c.marquevoiture[j]!='\0'; j++) {   

        if(c.marquevoiture[j] >= 'a' && c.marquevoiture[j] <= 'z') 
            {
                c.marquevoiture[j] = c.marquevoiture[j] -32;
            }
         }

    for (i=0;i<10;i++){
         if (strcmp(c.modelevoiture,modele_de_voiture[i])==0 && strcmp(c.marquevoiture,marque_de_voiture[i]))
            {f1=0;
            break;
            }
    }
    while (fread(&ca, sizeof(ca), 1, ptr),!feof(ptr))
       {
        if (strcmp(ca.modelevoiture, c.modelevoiture) == 0 && strcmp(ca.marquevoiture, c.marquevoiture) == 0)
        {
            if (ca.dateretour.a >= c.datelouer.a && ca.dateretour.m >= c.datelouer.m && ca.dateretour.j >= c.datelouer.j)
                 f2=1;
        }
        else
            f2=0;
            if((f2==1)||(f1==1)||(ca.etat=="en panne"))
               {
                 printf("La voiture n'est pas disponible. Vous souhaitez essayer une autre voiture ?\nSi oui, tapez 1, sinon tapez 0\n");
                 scanf("%d",&r);
                 fclose(ptr);
                 if(r==1)
                    louer_voiture();
                 else
                 {
                     printf("MERCI D'ÊTRE VENU!N'HESITEZ PAS A REVENIR \n");
                     fclose(ptr);
                     break;
                 }
               }
        
                else if(strcmp(ca.modelevoiture,c.modelevoiture)!=0 || ca.marquevoiture!=c.marquevoiture || f2==0)
        {
            printf("VOITURE VALABLE  \n");
            FILE *fp;
            fp=fopen("louer_voiture","a");
            strcpy(ca.modelevoiture,c.modelevoiture);
            ca.datelouer.j=c.datelouer.j;
            ca.datelouer.m=c.datelouer.m;
            ca.datelouer.a=c.datelouer.a;
            ca.dateretour.j=c.dateretour.j;
            ca.dateretour.m=c.dateretour.m;
            ca.dateretour.a=c.dateretour.a;
            fwrite(&ca,sizeof(ca),1,fp);
            fclose(fp);
            printf("ENTREZ VOTRE NOM: ");
            scanf("%s",c.nom_du_client);
            printf("ENTREZ VOTRE NUMERO D'IDENTIFICATION: ");
            scanf("%s",c.clientid);
            c.n=date_diff(c.datelouer.a,c.dateretour.a,c.datelouer.m,c.dateretour.m,c.datelouer.j,c.dateretour.j);
          for(j=0;j<10;j++)
            {
                x=strcmp(c.modelevoiture,modele_de_voiture[j]);
                if(x==0)
                    break;
            }
            c.loyer=c.n*location_voitureparjour[j];
            printf("Details:\n");
            printf("NOM:\t%s\nID:\t%s\nVOITURE LOUEE:\t%s\nNOMBRE DE JOURS:\t%d\nLOCATION:\t%d\n",c.nom_du_client,c.clientid,c.modelevoiture,c.n,c.loyer);
            fclose(ptr);
            strcpy(cr->nom_du_client, c.nom_du_client);;
            strcpy(cr->clientid, c.clientid);
            strcpy(cr->modelevoiture, c.modelevoiture);
            cr->n = c.n;
            cr->loyer = c.loyer;
            FILE *fptr;
            fptr=fopen("louer_voiture.txt","a+");
            fwrite(&cr,sizeof(cr),1,fptr);
            fclose(fptr);
            break;
        }
    }
}


void retourner_voiture()
{
    char id[13];
    int jj,mm,aa,j,m,a,f=0,i,d,r;
    printf("BIENVENUE CHER CLIENT \n");
    printf("ENTREZ VOTRE IDENTIFIANT S'IL VOUT PLAIT\n");
    scanf("%s",id);
    for(i=0;i<10;i++)
    {
        if(strcmp(cr[i].clientid,id)==0)
        {
            f=1;
            printf("SALUT %s\n",cr[i].nom_du_client);
            printf("Pour confirmation, veuillez indiquer la date a laquelle vous avez pris le vehicule et la date a laquelle vous le restituez dans le formulaire de demande de remboursement.(jj mm aaaa)format.\n");
            scanf("%d%d%d",&jj,&mm,&aa);
            scanf("%d%d%d",&d,&m,&a);
            cr[i].jours=date_diff(aa,a,mm,m,jj,d);
            if(cr[i].jours>cr[i].n)
            {
                    cr[i].loyer+=50*(cr[i].jours-cr[i].n);
            }
            printf("montant final:%d \n",cr[i].loyer);
            printf("\n\n");
            break;
        }
    }
    if(f==0)
           {
             printf("client non trouvee\n");
            
           }
        else
        {
            for(j=0;j<10;j++)
            {
                if(j==i)
                    memset(&cr[j].modelevoiture[0],0,sizeof(cr[j].modelevoiture[0]));
            }
           
        }
}
void reclamation(){
    char id[13];
    int jj,mm,aa,j,m,a,f=0,i,d,r;
    printf("BIENVENUE CHER CLIENT \n");
    printf("ENTREZ VOTRE IDENTIFIANT S'IL VOUT PLAIT\n");
    scanf("%s",id);
    
    for(i=0;i<10;i++)
    {
        if(strcmp(cr[i].clientid,id)==0)
        {
            f=1;
            printf("SALUT %s\n",cr[i].nom_du_client);
            printf("Pour confirmation, veuillez indiquer la date a laquelle vous avez pris le vehicule et la date a laquelle vous le restituez dans le formulaire de demande de remboursement.(jj mm aaaa)format.\n");
            scanf("%d%d%d",&jj,&mm,&aa);
            scanf("%d%d%d",&d,&m,&a);
            strcpy(cr[i].etat,"en panne");
            printf("nous sommes desoles pour le probleme que vous avez rencontre on peut vours rembourser tapez 1 si vous voulez ou choir une autre voiture tapez 2 ");
            scanf("%d",&r);
            switch(r){
                case 1 :printf("votre somme sera remboursee ");
                break;
                case 2 :louer_voiture();
                break ;
            }
            

        }
        if(f==0)
           {
             printf("client non trouvee\n");
           
           }
        else
        {
            for(j=0;j<10;j++)
            {
                if(j==i)
                    memset(&cr[j].modelevoiture[0],0,sizeof(cr[j].modelevoiture[0]));
            }
}
    }

}
int main()
{
    int q,p=0;
    
    printf("\nY A-T-IL UN NOUVEAU CLIENT MAINTENANT ?\nENTREZ 1 POUR OUI ET 0 POUR NON\n");
    scanf("%d", &p);
    while (p == 1) {
        printf("\aSALUT !! ETES-VOUS ICI POUR PRENDRE LE SERVICE DE VOITURE OU POUR RENDRE LA VOITURE ? \n 1. LOUER UNE VOITURE.\n 2. RETOURNER LA VOITURE.\n 3.FAIRE UNE RECLAMATION\n");
        scanf("%d", &q);
        switch (q) {
            case 1:
                louer_voiture();
                break;
            case 2:
                retourner_voiture();
                break;
            case 3:
                reclamation();
            break;
            default:
                printf("Choix incorrect ! Reessayez.\n");
                p=1;
                break;
        }
    }


        printf("\n\nMerci pour votre visite\n\n");
}  

