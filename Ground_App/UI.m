%UI

function UI()
   f = uifigure('name','MARS-GCS');
   set(f,'Position',[100 50 1300 800])
   
   gl = uigridlayout(f,[2,3]);
   gl.RowHeight = {'1x','1x','1x','1x'};
   gl.ColumnWidth = {'1x','1x','1x','1x'};
   
   config_tab_group = uitabgroup(gl);
   config_tab_group.Layout.Row = [2 3];
   config_tab_group.Layout.Column = 1;
   
   config_tab_1 = uitab(config_tab_group);
   config_tab_1.Title = 'Path Configuration';
   
   grid2 = uigridlayout(config_tab_1,[2,3]);
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
   
   terminal_tab_group = uitabgroup(gl);
   terminal_tab_group.Layout.Row = 4;
   terminal_tab_group.Layout.Column = 1;
   
   terminal_tab_1 = uitab(terminal_tab_group);
   terminal_tab_1.Title = 'Terminal';
   
   CMfield = uieditfield(terminal_tab_1, "Position",[10 120 290 23]);
   
   termnalField = uieditfield(terminal_tab_1, "Position",[10 10 290 100]);
   newText = ['MARS Terminal initialized - ', datestr(now)];
   termnalField.Value = newText;
   
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
             
   mapGeo = geoaxes(gl);
   mapGeo.Layout.Row = [1 2];
   mapGeo.Layout.Column = [3 4];
   title(mapGeo,'Position Map');
   latSeattle = 47.62;
   lonSeattle = -122.33;
   latAnchorage = 61.20;
   lonAnchorage = -149.9;
   geoplot(mapGeo,[returnLatitudeData()],[returnLongitudeData()],'g-*')
   geobasemap(mapGeo,'streets-dark')
   
   
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
   
   tg = uitabgroup(gl);
   tg.Layout.Row = [3 4];
   tg.Layout.Column = 4;
   
   Data1tab = uitab(tg);
   Data1tab.Title = 'Raw Data';
   % Define the table data
   data = cell(12,2);
   data{1,1} = 'Variable'; % Predefined column name
   data{1,2} = 'Value'; % Predefined column name
   
   for i = 2:14
       data{i,2} = 0; % Random data in column 2
   end

   %Names
   data{2,1} = 'Latitude';
   data{3,1} = 'Longitude';
   data{4,1} = 'Satellites';
   data{5,1} = 'Pitch';
   data{6,1} = 'Roll';
   data{7,1} = 'Yaw';
   data{8,1} = 'AngleX';
   data{9,1} = 'AngleY';
   data{10,1} = 'AngleZ';
   data{11,1} = 'motorFL';
   data{12,1} = 'motorFR';
   data{13,1} = 'motorRL';
   data{14,1} = 'motorRR';
   
   %Values
   
   % Create a uitable with the data
   t = uitable(Data1tab,'Data',data);

   % Set the column widths
   t.ColumnWidth = {150, 150};

   % Set the row names
   t.RowName = [];

   % Set the first row as bold
   t.FontWeight = 'bold';
   t.Data{1,1} = 'Variable';
   t.Data{1,2} = 'Value';

   % Set the table size
   t.Position = [5 28 302 355];
   
   Guagetab = uitab(tg);
   Guagetab.Title = 'Data Guages';
   velocityGuagetext = uilabel(Guagetab);
   velocityGuagetext.HorizontalAlignment = 'left';
   velocityGuagetext.Text = 'Velocity -';
   velocityGuagetext.Position = [50 280 100 60];
   velocityg = uigauge(Guagetab, "Position",[135 200 150 150]);
   velocityg.Value = 45;
   
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

    x = linspace(0, 10, 100);
    % Link the data of Plot 1 and Plot 2
    linkdata on;
    
    time = 0;
    bse = 1;
     % Function to update the plots continuously
    function updatePlots()
        %Update Raw
        data{2,2} = returnLatitudeData();
        data{3,2} = returnLongitudeData();
        data{4,2} = returnSatellitesData();
        data{5,2} = returnPitchData();
        data{6,2} = returnRollData();
        data{7,2} = returnYawData();
        data{8,2} = returnAngleXdata();
        data{9,2} = returnAngleYData();
        data{10,2} = returnAngleZData();
        data{11,2} = returnmotorFLData();
        data{12,2} = returnmotorFRData();
        data{13,2} = returnmotorRLData();
        data{14,2} = returnmotorRRData();
        
        % Update the table's data property
        set(t, 'Data', data);

        y2 = cos(x + now * rand());  % Example update function for Plot 2
        time = time + bse;
        test = 0.5 + bse;
        % Update the data of Plot 1 and Plot 2
        plot(pl,time,test);
        plot(gx,time,returnVelocityData());
        plot(lx,time,returnThrottleData());
        plot(hx, x, y2);
        
        % Update the plots
        drawnow;
    end

    % Call the updatePlots function continuously
    while true
        updatePlots();
    end
end