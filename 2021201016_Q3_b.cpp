#include <iostream>
using namespace std;


// void sum(double **first,int count1,double **second,int count2,double **third){
    
//     int i=0,j=0,k=0; 
//     while(i<count1 && j<count2){
//         if(first[0][i]==second[0][j]){
//             if(first[1][i]==second[1][j]){
//                 third[0][k]=first[0][i];
//                 third[1][k]=first[1][i];
//                 third[2][k]=first[2][i]+second[2][j];
//                 i++;
//                 j++;
//                 k++;
//             }else if(first[1][i]<second[1][j]){
//                 third[0][k]=first[0][i];
//                 third[1][k]=first[1][i];
//                 third[2][k]=first[2][i];
//                 i++;
//                 k++;
//             }else{
//                 third[0][k]=second[0][j];
//                 third[1][k]=second[1][j];
//                 third[2][k]=second[2][j];
//                 j++;
//                 k++;
//             }
//         }else if(first[0][i]<second[0][j]){
//                 third[0][k]=first[0][i];
//                 third[1][k]=first[1][i];
//                 third[2][k]=first[2][i];
//                 i++;
//                 k++;
//         }else{
//                 third[0][k]=second[0][j];
//                 third[1][k]=second[1][j];
//                 third[2][k]=second[2][j];
//                 j++;
//                 k++;
//         }
//     }
//     while(i<count1){
//                 third[0][k]=first[0][i];
//                 third[1][k]=first[1][i];
//                 third[2][k]=first[2][i];
//                 i++;
//                 k++;
//     }
//     while(j<count2){
//                 third[0][k]=second[0][j];
//                 third[1][k]=second[1][j];
//                 third[2][k]=second[2][j];
//                 j++;
//                 k++;  
//     }
// }

// double** transpose(double **trace,int count,double **first,int col,int row){
//     int total[col];
//     int k=0;
//     for(int j=0;j<col;j++){
//         int val=0;
//         for(int i=0;i<row;i++){
//             if(first[i][j]){
//                 val++;
//             }
//         }
//         total[k++]=val;
//     }
//     int index[col+1];
//     index[0]=1;
//     for(int i=1;i<=col;i++){
//         index[i]=index[i-1]+total[i-1];
//     }
//     double** ans= new double*[3];
//     for(int i=0;i<3;i++){
//       ans[i] = new double[count];  
//     }
//     for(int i=0;i<count;i++){
//         int d=trace[1][i];
//         int in=index[d];
//         ans[0][in-1]=trace[1][i];
//         ans[1][in-1]=trace[0][i];
//         ans[2][in-1]=trace[2][i];
//         index[d]++;
//     }

//     return ans;
//     // ans is the final transpose matrix

// }


void sort(double **temp,int k){
    bool unsort=true;
    while(unsort){
        unsort=false;
        int i=0;
        while(i<k-1){
            
            if(temp[0][i]>temp[0][i+1]){
                int x=temp[0][i];
                temp[0][i]=temp[0][i+1];
                temp[0][i+1]=x;

                int y=temp[1][i];
                temp[1][i]=temp[1][i+1];
                temp[1][i+1]=y;

                double z=temp[2][i];
                temp[2][i]=temp[2][i+1];
                temp[2][i+1]=z;

                unsort=true;
            }
            i++;
        }
    }
unsort = true;
while(unsort){
        unsort=false;
        int i=0;
        while(i<k-1){
            
            if((temp[0][i]==temp[0][i+1])&&(temp[1][i]>temp[1][i+1])){
               
                int y=temp[1][i];
                temp[1][i]=temp[1][i+1];
                temp[1][i+1]=y;

                double z=temp[2][i];
                temp[2][i]=temp[2][i+1];
                temp[2][i+1]=z;

                unsort=true;
            }
            i++;
        }
    }


}

void multiplication(double **first,int count1,double **second,int count2){
    int size=0;
    double** res= new double*[3];
    for(int i=0;i<3;i++){
        res[i]=new double[count1*count2];
    }
    int k=0;
    for(int i=0;i<count1;i++){
        for(int j=0;j<count2;j++){
            if(first[1][i]==second[0][j]){
                res[0][k]=first[0][i];
                res[1][k]=second[1][j];
                res[2][k]=first[2][i]*second[2][j];
                k++;
                size++;
            }
        }
    }
    double** answer= new double*[3];
    for(int i=0;i<3;i++){
        answer[i]=new double[size];
    }
    for(int i=0;i<size;i++){
        answer[0][i]=res[0][i];
        answer[1][i]=res[1][i];
        answer[2][i]=res[2][i];
    }
    int t=0;
    sort(answer,size);
    for(int i=0;i<size-1;i++){
        if(answer[0][i]==answer[0][i+1]){
            if(answer[1][i]==answer[1][i+1]){
                answer[2][i]=answer[2][i]+answer[2][i+1];
                t++;
                answer[0][i+1]=-1;
            }
        }
    }
    double** finally= new double*[3];
    for(int i=0;i<3;i++){
        finally[i]=new double[size-t];
    }
    int l=0;

    for(int i=0;i<size;i++){
        if(answer[0][i]!=-1){
            finally[0][l]=answer[0][i];
            finally[1][l]=answer[1][i];
            finally[2][l]=answer[2][i];
            l++;
        }
    }
    cout<<"row: ";
    for(int i=0;i<size-t;i++){
        cout<<finally[0][i]<<" ";
    }
    cout<<endl;
    cout<<"col: ";
    for(int i=0;i<size-t;i++){
        cout<<finally[1][i]<<" ";
    }
    cout<<endl;
    cout<<"value: ";
    for(int i=0;i<size-t;i++){
        cout<<finally[2][i]<<" ";
    }
    
}



int main(){
    int row,col;
    cin>>row>>col;
    double** matrix1 = new double*[row];
    for(int i=0; i<row; i++)
    {
     matrix1[i] = new double[col];
    }
    double** matrix2 = new double*[row];
    for(int i=0; i<row; i++)
    {
        matrix2[i] = new double[col];
    }
    int count1=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix1[i][j];
            if(matrix1[i][j]){
                count1++;
            }
        }
    }
    int count2=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix2[i][j];
            if(matrix2[i][j]){
                count2++;
            }
        }
    }
    int k=0;
    double** trace1= new double*[3];
    for(int i=0;i<3;i++){
      trace1[i] = new double[count1];  
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
        if(matrix1[i][j]){
            trace1[0][k]=i;
            trace1[1][k]=j;
            trace1[2][k]=matrix1[i][j];
            k++;
        }
        }
    }

   // trace1=transpose(trace1,count1,matrix1,col,row);
    //it will give transpoose of the matrix
    k=0;
    double** trace2= new double*[3];
    for(int i=0;i<3;i++){
      trace2[i] = new double[count2];  
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix2[i][j]){
                trace2[0][k]=i;
                trace2[1][k]=j;
                trace2[2][k]=matrix2[i][j];
                k++;
            }
        }
    }

multiplication(trace1,count1,trace2,count2);

    // int count3=0;
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         if(matrix1[i][j] || matrix2[i][j]){
    //             count3++;
    //         }
    //     }
    // }
    // double** third= new double*[3];
    // for(int i=0;i<3;i++){
    //   third[i] = new double[count3];  
    // }
    // sum(trace1,count1,trace2,count2,third);
    //will give the sum of both
  //  for(int i=0;i<count3;i++){
    //    cout<<third[2][i];
    //} //use to print

}