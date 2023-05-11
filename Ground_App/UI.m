%UI
%UI
function UI()
   f = uifigure('name','MARS-GCS');
   set(f,'Position',[100 50 1300 800])
   
   gl = uigridlayout(f,[2,3]);
   gl.RowHeight = {'1x','1x','1x','1x'};
   gl.ColumnWidth = {'1x','1x','1x','1x'};

   p = uipanel(gl,'Title','Path Configuration');
   p.Layout.Row = [2, 3];  % Span the panel across all rows
   
   grid2 = uigridlayout(p,[2,3]);
   grid2.RowHeight = {22,22,22};
   grid2.ColumnWidth = {'1x'};
   
   im = uiimage(f);
   im.ImageSource = "LOGO.jpg";
   set(im,'Position',[50 545 270 450])
   
   w = uipanel(gl,'Title','State');
   w.Layout.Row = 1;
   w.Layout.Column = 1;
   

   k = uiknob(w,'discrete',"Position",[113 30 70 70]);
   k.Items = {'IDLE', 'PREP', 'ARMED', 'BYPASS'};
   
   terminalPanel = uipanel(gl,'Title','Terminal');
   terminalPanel.Layout.Row = 4;
   terminalPanel.Layout.Column = 1;
   
   CMlabel = uilabel(terminalPanel,"Position",[10 150 200 15]);
   CMlabel.HorizontalAlignment = 'left';
   CMlabel.Text = 'Command';

   CMfield = uieditfield(terminalPanel, "Position",[10 120 290 23]);
   
   termnalField = uieditfield(terminalPanel, "Position",[10 10 290 100]);
   
   %Path Density
   pDlabel = uilabel(grid2);
   pDlabel.HorizontalAlignment = 'left';
   pDlabel.Text = 'Swarm Density';

   promptPD = uieditfield(grid2);
   
   %Final Point X
   pFXlabel = uilabel(grid2);
   pFXlabel.HorizontalAlignment = 'left';
   pFXlabel.Text = 'Final Point (Latitude)';

   promptFX = uieditfield(grid2);
   
   %Final Point Y
   pFYlabel = uilabel(grid2);
   pFYlabel.HorizontalAlignment = 'left';
   pFYlabel.Text = 'Final Point (Longitude)';

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
   fx.Layout.Column = [3 4];
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
   title(lx,'Throttle');
   
   missionPanel = uipanel(gl,'Title','Mission');
   missionPanel.Layout.Row = [1 2];
   missionPanel.Layout.Column = 2;
   
   rwDataPanel = uipanel(gl,'Title','Raw Data');
   rwDataPanel.Layout.Row = [3 4];
   rwDataPanel.Layout.Column = 4;
   
   %
   wingFL = uilabel(rwDataPanel);
   wingFL.HorizontalAlignment = 'left';
   wingFL.Text = 'Wing - FL';
   wingFL.Position = [100 100 100 60];
   wingFLout = uilabel(rwDataPanel);
   wingFLout.HorizontalAlignment = 'right';
   wingFLout.Text = '0';

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
   btn3.Text = 'Update Configuration';
   btn3.ButtonPushedFcn = @Instructions_Description;
   

    % Create the axes to hold the artificial horizon diagram
    ax = uiaxes(missionPanel, 'Position', [0 0 320 370]);
    ax.XLim = [-1 1];
    ax.YLim = [-1 1];
    ax.XTick = [];
    ax.YTick = [];
    ax.Box = 'on';
    ax.Color = 'k';
    title(ax, 'Artificial Horizon');

    % Define artificial horizon background colors
    skyColor = [0.529 0.808 0.922]; % Light blue
    groundColor = [0.545 0.271 0.075]; % Brown

    % Draw artificial horizon background
    patch(ax, [-1 1 1 -1], [-1 -1 0 0], skyColor); % Sky
    patch(ax, [-1 1 1 -1], [0 0 1 1], groundColor); % Ground

    % Draw pitch lines
    numLines = 11;
    lineLength = 0.04;
    pitchAngles = linspace(-10, 10, numLines);
    for i = 1:numLines
        y = lineLength * sin(deg2rad(pitchAngles(i)));
        line(ax, [-1 1], [y y], 'Color', 'w', 'LineStyle', '-', 'LineWidth', 1);
    end

    % Define airplane symbol
    airplane = patch(ax, [-0.1 0.1 0], [0 -0.2 0], 'w');

    % Define animation parameters
    roll = 0; % initial roll angle
    pitch = 0; % initial pitch angle
    rollRate = 2; % roll rate (degrees per second)
    pitchRate = 1; % pitch rate (degrees per second)
    dt = 0.1; % animation time step

   
    % Link the data of Plot 1 and Plot 2
    linkdata on;
    
    % Call the updatePlots function continuously
    while true
        x = updateDataPlots(pl,gx,lx,hx);
    end
end