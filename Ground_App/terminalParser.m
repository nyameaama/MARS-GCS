function terminalParser(src,event,ref,input)
    % Split the input string by whitespace
    parts = strsplit(input, ' ');

    % Check if the input contains a command and a value
    if numel(parts) < 2
        newText = 'Invalid command parts';
        ref.Value = newText;
        return;
    end

    % Extract the command and value
    command = parts{1};
    value = str2double(parts{3});

    % Check the command and perform the corresponding action
    switch command
        case 'set'
            % Check the specific sub-command
            subCommand = parts{2};
            switch subCommand
                case 'wing-FL'
                    % Perform action for wing-FL
                    newText = ['Setting wing-FL to ',num2str(value)];
                    ref.Value = newText;      
                case 'wing-FR'
                    % Perform action for wing-FR
                    newText = ['Setting wing-FR to ',num2str(value)];
                    ref.Value = newText;
                case 'wing-RL'
                    % Perform action for wing-RL
                    newText = ['Setting wing-RL to ',num2str(value)];
                    ref.Value = newText;      
                case 'wing-RR'
                    % Perform action for wing-RR
                    newText = ['Setting wing-RR to ',num2str(value)];
                    ref.Value = newText;
                case 'throttle'
                    % Perform action for throttle
                    newText = ['Setting throttle to ',num2str(value)];
                    ref.Value = newText;
                case 'set-targetLong'
                    % Perform action for set-targetLong
                    newText = ['Setting Target Longitude to ',num2str(value)];
                    ref.Value = newText;
                    
                case 'set-targetLat'
                    % Perform action for set-targetLat
                    newText = ['Setting Target Latitude to ',num2str(value)];
                    ref.Value = newText;
                case 'set-vehicleState'
                    % Perform action for set-vehicleState
                    newText = ['Setting Vehicle State to ',num2str(value)];
                    ref.Value = newText;
                otherwise
                    newText = 'Invalid command';
                    ref.Value = newText;
            end
        otherwise
            newText = 'Invalid command';
            ref.Value = newText;
    end
end
