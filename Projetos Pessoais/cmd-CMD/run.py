import time
import os
import subprocess
import qrcode
import pygame
from threading import Thread
import tkinter as tk
from tkinter import messagebox
import webbrowser

OBS_TIMER_FILE = "obs_timer.txt"

def chat_stream():
    
    url = "https://chat.restream.io/chat"
    
    webbrowser.open(url)
    menu()


def detect_obs():
    #Check if OBS Studio is running
    try:
        result = subprocess.check_output("tasklist", shell=True, text=True)
        return "obs64.exe" in result.lower() or "obs32.exe" in result.lower()
    except Exception as e:
        print(f"Error detecting OBS: {e}")
        return False


def write_to_obs_timer_file(timer_text, current_cycle, total_cycles, name_cycle):
    with open(OBS_TIMER_FILE, "w") as file:
        file.write(f"{name_cycle} {current_cycle}/{total_cycles}\n{timer_text}")


def show_notification(message):
    root = tk.Tk()
    root.withdraw() 
    root.attributes("-topmost", True)  # Keep the messagebox on top of all windows
    messagebox.showinfo("Pomodoro Timer", message)
    root.destroy()


def play_sound(file_path):
    pygame.mixer.init()
    pygame.mixer.music.load(file_path)
    pygame.mixer.music.play(loops=0, start=0.0)


def countdown_timer(duration, message, obs_mode, current_cycle, total_cycles, name_cycle):
    """Countdown timer for Pomodoro cycles."""
    while duration > 0:
        minutes, seconds = divmod(duration, 60)
        timer_text = f"{minutes:02}:{seconds:02}"
        print(timer_text, end="\r")

        if obs_mode:
            write_to_obs_timer_file(timer_text, current_cycle, total_cycles, name_cycle)
        
        time.sleep(1)
        duration -= 1
    
    # Timer ended
    play_sound("Boxing Bell Sound Effect.mp3")  # Replace with your MP3 file path
    show_notification(message)


def disable_notifications():
    # Command to disable all notifications
    cmd = 'powershell -Command "& {New-ItemProperty -Path HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings -Name NOC_GLOBAL_SETTING_ENABLED -Value 0 -PropertyType DWord -Force}"'
    subprocess.run(cmd, shell=True)
    

def enable_notifications():
    # Command to re-enable notifications
    cmd = 'powershell -Command "& {New-ItemProperty -Path HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings -Name NOC_GLOBAL_SETTING_ENABLED -Value 1 -PropertyType DWord -Force}"'
    subprocess.run(cmd, shell=True)
    
    
def main():
    file_path = "config.txt"
    
    try:
        with open(file_path, "r+") as file:
            first_line = file.readline()
            if first_line: #If has the first line, display it
                nome = first_line.strip()
                print("#" * 20)
                print(f"Hello {nome}")
                print("#" * 20)
                print("\n")
                print("@@@@@@@@@@@@@@@@@@@@")
                print("@    Main Menu     @")
                print("@@@@@@@@@@@@@@@@@@@@\n")
                print("----------------------------------------")
                print("pmdr - Pomodoro timer")
                print("sch - Schedule Tasks")
                print("cld - Calendar")
                print("chat - Open Restream chat on Web Browser")
                print("alarm - QR Code 'Alarm OFF'")
                print("end - Exit")
                print("----------------------------------------")
                menu()
            else:
                nome=str(input("Enter your name: \n"))
                file.write(nome + "\n") #If not, saves it and move on
                file.flush()
                print("#" * 20)
                print(f"Hello {nome}")
                print("#" * 20)
                print("\n")
                print("@@@@@@@@@@@@@@@@@@@@")
                print("@    Main Menu     @")
                print("@@@@@@@@@@@@@@@@@@@@\n")
                print("----------------------------")
                print("pmdr - Pomodoro timer")
                print("sch - Schedule Tasks")
                print("cld - Calendar")
                print("alarm - QR Code 'Alarm OFF'")
                print("end - Exit")
                print("----------------------------")
                menu()
    except FileNotFoundError:
        with open(file_path, "w") as file: #if the file does not exist, create one and save the name
            nome=str(input("Enter your name: \n"))
            file.write(nome + "\n")
            file.flush()
            print("#" * 20)
            print(f"Hello {nome}")
            print("#" * 20)
            print("\n")
            print("@@@@@@@@@@@@@@@@@@@@")
            print("@    Main Menu     @")
            print("@@@@@@@@@@@@@@@@@@@@\n")
            print("----------------------------")
            print("pmdr - Pomodoro timer")
            print("sch - Schedule Tasks")
            print("cld - Calendar")
            print("alarm - QR Code 'Alarm OFF'")
            print("end - Exit")
            print("----------------------------")
            menu()
    

def schedule():
    choice_schedule=str(input("S>"))
    
    #------If choice is "read"
    if choice_schedule.lower() == "read":
        print("Schedule list: \n")
        file_path=open("schedule.txt", "r")
        print(file_path.read())
        schedule
                
    if choice_schedule == "help": #-------Command for help
        print("Only 'back', 'write', 'delete' commands available.")
    
    #------If choice is "write"    
    if choice_schedule.lower() == "write":
        while True:
            task = input("What is the task: \n")
            try:
                with open('schedule.txt', 'a+') as file:
                    file.write(f"{task}\n")
                    file.flush()
                    print("Task added successfully!")
            except Exception as e:
                print(f"Error: {e}")
        
            while True:
                next_action = input("S>>").lower()
                if next_action == "back":
                    schedule()
                    return
                elif next_action == "add":
                    break  #End loop and restart the condition to add another task
    
    #------If choice is "back"
    if choice_schedule.lower() == "back":
        menu()
    
    
    #------If choice is "delete"    
    if choice_schedule.lower() == "delete":  # If "delete" was chosen
        try:
            while True:
                with open('schedule.txt', 'r') as file:
                    lines = file.readlines()  # Read all lines from the file
            
                if not lines: #If file is empty
                    print("The schedule is empty.")
                    while True:
                        back = input("S>>")
                        if back == "back":
                            schedule()
                            break 
                        elif back == "help":
                            print("Only 'back' command available.")
                        else:
                            print("Please type a valid command.")
            
                print("\nHere are the current tasks:")
                for index, line in enumerate(lines, start=1):
                    print(f"{index}. {line}")  # Display each task with a number
            
                delete_choice = input("\nEnter the number of the task to delete (or type 'back' to go back): \n>>").strip()
                if delete_choice.lower() == "back":
                    schedule()
                    break
            
                try:
                    delete_choice = int(delete_choice)  # Convert the choosen number to an integer
                    if 1 <= delete_choice <= len(lines):  # Check if the choice is valid
                        del lines[delete_choice - 1]  # Remove the chosen line
                        with open('schedule.txt', 'w') as file:
                            file.writelines(lines)  # Write the updated lines back to the file
                        print("Task deleted successfully!")
                    else:
                        print(f"Please choose a valid number between 1 and {len(lines)}.")
                except ValueError:
                    print("Invalid input. Please enter a valid number or type 'back'.")
        except FileNotFoundError:
            print("The schedule file does not exist. Please add tasks first.")
            schedule()
        except Exception as e:
            print(f"An unexpected error occurred: {e}")
    
    if choice_schedule.lower() != "delete" or choice_schedule.lower() == "write" or choice_schedule.lower() == "read" or choice_schedule.lower() == "delete":
        schedule()
        
    
def menu():
    
    while True:
        choice = str(input("\nM>")).lower()
        if choice == "pmdr": 
            pomodoro()
            break
        elif choice == "sch":
            print("\n")
            print("@@@@@@@@@@@@@@@@@@@@")
            print("@     Schedule     @")
            print("@@@@@@@@@@@@@@@@@@@@\n")
            print("--------------------------------")
            print("read - Read and list saved tasks")
            print("write - Write new task")
            print("delete - Delete a selected task")
            print("back - Go back to the Main Menu")
            print("--------------------------------")
            schedule()
            break
        elif choice == "cld":
            calendar()
            break
        elif choice == "chat":
            chat_stream()
            break
        elif choice == "end":
            print("Ok, bye!")
            exit()
        elif choice == "alarm":
            alarm()
            break
        elif choice == "help":
            print("pmdr - Pomodoro timer")
            print("sch - Schedule Tasks")
            print("cld - Calendar")
            print("chat - Open Restream chat on Web Browser")
            print("alarm - QR Code 'Alarm OFF'")
            print("end - Exit")
            print("----------------------------------------")
            
           
   
def alarm():
    data = "https://picsum.photos/200/300/?blur"
    qr = qrcode.QRCode(border=1)
    qr.add_data(data)  # Add URL data to the QR code
    qr.make(fit=True)
    qr.print_ascii(invert=False) # Print the QR code as ASCII text to be displayed
    menu()
            
            
def pomodoro():
    print("------------------------------")
    print("Welcome to the Pomodoro Timer!")
    print("------------------------------")
    study_time = int(input("Enter study time (minutes): \n>")) * 60
    break_time = int(input("Enter break time (minutes): \n>")) * 60
    total_cycles = int(input("Enter number of cycles: \n>"))
    
    with open('schedule.txt', 'r') as file:
        lines = file.readlines()  # Read all lines from the file

    # Display lines and ask for a choice
    for index, line in enumerate(lines):
        print(f"{index + 1}: {line.strip()}")

    chosen_line = int(input("Enter the number of the line you want to select: ")) - 1
   
    #Detect if OBS is running
    obs_mode = detect_obs()
   
    if obs_mode:
        print("OBS detected. Timer will be displayed on your livestream.")
    else:
        print("OBS not detected. Proceeding normally.")
    disable_notifications()
    current_cycle = 1
    
    while current_cycle <= total_cycles:
       print(f"{lines[chosen_line].strip()} \nCycle {current_cycle}/{total_cycles}")
       
           
       while True:
           study = input("Type 'study' to begin or 'cancel' to return to the menu: \n>").strip().lower()
           if study == "study":
               name_cycle = "Study"
               countdown_timer(study_time, "Study session complete! Time for a break.", obs_mode, current_cycle, total_cycles, name_cycle)
               break
           elif study == "cancel":
               print("Returning to menu...")
               enable_notifications()
               write_to_obs_timer_file("00:00", 0, 0, "Cycle")
               menu()
               break
        
        # Start break timer
       if current_cycle < total_cycles:
           while True:
               break_input = input("Type 'break' to begin or 'cancel' to return to the menu: \n>").strip().lower()
               if break_input == "break":
                   name_cycle = "Break"
                   countdown_timer(break_time, "Break over! Back to studying.", obs_mode, current_cycle, total_cycles, name_cycle)
                   break
               elif break_input == "cancel":
                   print("Returning to menu...")
                   enable_notifications()
                   write_to_obs_timer_file("00:00", 0, 0, "Cycle")
                   menu()
                   break
                    
       current_cycle += 1
    
    print("Pomodoro session complete! Great job!")
    
    enable_notifications()
    if obs_mode:
       write_to_obs_timer_file("00:00", 0, 0, "Cycle")
    menu()
        
def calendar():
    print("W.I.P.")
    
        

if __name__== "__main__":
    main()
    
    
    