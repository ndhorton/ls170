#!/bin/bash

is_in_collection() {
        local search_term="$1"
        local collection="$2"
        local old_ifs=$IFS
        IFS=';'1

        for item in collection; do 
                if [[ "$item" == "$search_term" ]]; then
                        IFS=$old_ifs
                        return 0
                fi
        done

        IFS=$old_ifs
        return 1 
}


thirty_days="4;6;9;11"
month_rollover="false"

day=$( date +%-d )
month=$( date +%-m )
year=$( date +%Y )


if [[ $day == "28" && $month == "2" ]]; then
        day=1
        month_rollover="true"
elif is_in_collection "$month" thirty_days && [[ $day == "30" ]]; then
        day=1
        month_rollover="true"
elif [[ $day == "31" ]]; then
        day=1
        month_rollover="true"
fi


if [[ $month_rollover == "true" && $month == "12" ]]; then
        month=1
        (( year++ ))
elif [[ $month_rollover == "true" ]]; then
        (( month++ ))
else
        (( day++ ))
fi

printf "Tomorrow's date is %02d-%02d-%04d\n" $month $day $year


