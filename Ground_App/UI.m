%UI
%UI
function UI()
    %initial point
   pointInitialX = 0;
   pointInitialY = 0;
   
   currentPosX = pointInitialX;
   currentPosY = pointInitialY;

   %end point
   endpointX = 0;
   endpointY = 0;

   exploredNodesX = [];
   exploredNodesY = [];


   %Create node map 
   xrand = (rand(1,500)*1000);
   yrand = (rand(1,500)*1000);

   f = uifigure('name','MARS-GCS');
   set(f,'Position',[100 50 1250 800])
   
   gl = uigridlayout(f,[2,3]);
   gl.RowHeight = {'1x','1x','1x','1x'};
   gl.ColumnWidth = {'1x','1x','1x'};

   p = uipanel(gl,'Title','Path Configuration');
   p.Layout.Row = [2, 3];  % Span the panel across all rows
   
   grid2 = uigridlayout(p,[2,3]);
   grid2.RowHeight = {22,22,22};
   grid2.ColumnWidth = {'1x'};
   
   w = uipanel(gl,'Title','Application');
   w.Layout.Row = 1;
   w.Layout.Column = 1;
   im = uiimage(w,"ImageSource","LOGO.jpg");
   im.ScaleMethod = "none";
   set(im,'Position',[50 50 200 400])
   
   % Routes drop-down
    modeRoutes = uidropdown(w);
    modeRoutes.Items = {'IDLE', 'PREP', 'ARMED', 'BYPASS'};
   
   n = uipanel(gl,'Title','Terminal');
   n.Layout.Row = 4;
   n.Layout.Column = 1;
   
   %Path Density
   pDlabel = uilabel(grid2);
   pDlabel.HorizontalAlignment = 'right';
   pDlabel.Text = 'Swarm Density';

   promptPD = uieditfield(grid2);
   
   %Final Point X
   pFXlabel = uilabel(grid2);
   pFXlabel.HorizontalAlignment = 'right';
   pFXlabel.Text = 'Final Point (X)';

   promptFX = uieditfield(grid2);
   
   %Final Point Y
   pFYlabel = uilabel(grid2);
   pFYlabel.HorizontalAlignment = 'right';
   pFYlabel.Text = 'Final Point (Y)';

   promptFY = uieditfield(grid2);
  
   cbx = uicheckbox(grid2, 'Text','Show units in output',...
                 'Value', 0,...
                 'Position',[50 50 102 15],...
                 'FontSize',13,...
                 'WordWrap','on');
             
   cbx2 = uicheckbox(grid2, 'Text','Show nodes instead of path        (Will not trace route between the chosen nodes)',...
                 'Value', 0,...
                 'Position',[50 50 102 15],...
                 'FontSize',13,...
                 'WordWrap','on');
             
   cbx3 = uicheckbox(grid2, 'Text','Show visualizati-on in new window',...
                 'Value', 1,...
                 'Position',[50 50 102 15],...
                 'FontSize',13,...
                 'WordWrap','on');
    
   cbx4 = uicheckbox(grid2, 'Text','Optimize Performance (Computation will take a shorter time period)',...
                 'Value', 0,...
                 'Position',[50 50 102 15],...
                 'FontSize',13,...
                 'WordWrap','on');
             
   
   fx = uiaxes(gl); 
   fx.Layout.Row = [1 2];
   fx.Layout.Column = [2 3];
   title(fx,'Position Map');
   
   pl = uiaxes(gl); 
   pl.Layout.Row = 3;
   pl.Layout.Column = 2;
   title(pl,'Altitude');
   
   gx = uiaxes(gl); 
   gx.Layout.Row = 3;
   gx.Layout.Column = 3;
   title(gx,'Velocity');

   hx = uiaxes(gl); 
   hx.Layout.Row = 4;
   hx.Layout.Column = 3;
   title(hx,'R1');

   lx = uiaxes(gl); 
   lx.Layout.Row = 4;
   lx.Layout.Column = 2;
   title(lx,'R2');
   
   % Create and lay out button
   %btn = uibutton(gl);
   %btn.Layout.Row = 2;
   %btn.Layout.Column = 1;
   %btn.Text = 'Run Simulation';
   % Assign button callback function
   %btn.ButtonPushedFcn = {@plotButtonPushed,currentPosX,currentPosY,xrand,yrand,exploredNodesX,exploredNodesY,promptIX,promptIY,promptFX,promptFY,promptPD,cbx,cbx2,cbx3,cbx4};
       
   % Create and lay out button
   %btn2 = uibutton(gl);
   %btn2.Layout.Row = 2;
   %btn2.Layout.Column = 2;
   %btn2.Text = 'Export Data to File';
   %btn2.ButtonPushedFcn = {@ExportProcess,xrand,yrand,cbx};
   
   btn3 = uibutton(grid2);
   btn3.Text = 'View Program Description';
   btn3.ButtonPushedFcn = @Instructions_Description;

end