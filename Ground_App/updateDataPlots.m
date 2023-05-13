function updateDataPlots(plot1,plot2,plot3,plot4)
    % Generate initial data for Plot 1 and Plot 2
    x = linspace(0, 10, 100);
        
        % Generate new data for Plot 1 and Plot 2
        y1 = sin(x + now * rand());  % Example update function for Plot 1
        y2 = cos(x + now * rand());  % Example update function for Plot 2

        % Update the data of Plot 1 and Plot 2
        plot(plot1, x, y1);
        plot(plot2, x, y2);
        plot(plot3, x, y1);
        plot(plot4, x, y2);
        % Update the plots
        drawnow;
end