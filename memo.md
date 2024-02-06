
Sample code from p.220

```
do lambda = min to max by (max-min) / res;       // Scan lambda
    X=X0;                                       // Set initial point, X0
    do i = 1 to N;                              //Iteration loop
        x = lambda*x* (1+x) ** (-beta);         // Generating equation
        SetColor(i);                            //Set color based on iteration
        PlotDot (lambda, x);                    // Plot dot at point (lambda,x)
    end;                                        // End Iteration loop
end;                                            // End lambda loop
```


```
xinc=pres/ (xxmax-xxmin) ;（* controls x-pixel position *）
yinc=pres/ (yymax-yymin) ; (* controls y-pixel position *)
a=2.24;b=・43;C=-.65:d=-2.43;e=1； (* control parameters *)
p（*，*）=0； (* initialize p array *)
X,Y,z＝0；（* starting point *)
do j = 1 to iter1;
    do i = 1 to iter2;
    xx = sin (a*y)-z*cos (b*x) ;
    yy = z*sin(c*x) -cos (d*y) ;
    zz = e*sin(x) ;
    x = xx; y =yy; z=zz；
    if xx<xxmax & xx>xxmin & yy < yymax & yy > yymin then do;
        xxx= (xx-xxmin) *xinc; (* scale to range (0, pres) *)
        УУУ= (yy-yymin) *yinc; (* scale to range (0, pres) *)
        р(ххх, ууу) = р (ххх, yyy) + 1;
        end;;
    end
end

```